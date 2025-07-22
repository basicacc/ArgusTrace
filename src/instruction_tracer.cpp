#include "dr_api.h"
#include "drmgr.h"
#include "drx.h"
#include <string.h>
#include <stdio.h>

#ifdef WINDOWS
#include <windows.h>
#include <winnt.h>
#endif

static file_t log_file;
static file_t modules_file;
static void *mutex;
static bool modules_enumerated = false;
static app_pc main_entry_point = NULL;

static const char* get_module_name_for_address(app_pc addr)
{
    module_data_t *mod = dr_lookup_module(addr);
    if (mod) {
        const char *module_name = dr_module_preferred_name(mod);
        if (!module_name) {
            module_name = mod->names.module_name;
        }
        
        static char module_buffer[256];
        if (module_name) {
            strncpy(module_buffer, module_name, sizeof(module_buffer) - 1);
            module_buffer[sizeof(module_buffer) - 1] = '\0';
        } else {
            strcpy(module_buffer, "unknown");
        }
        
        dr_free_module_data(mod);
        return module_buffer;
    }
    
    return "unknown";
}

static void enumerate_module_exports(module_data_t *mod, const char *module_name)
{
    if (!mod) return;
    
#ifdef WINDOWS
    app_pc base = mod->start;
    
    __try {
        IMAGE_DOS_HEADER *dos_header = (IMAGE_DOS_HEADER *)base;
        
        if (dos_header->e_magic != IMAGE_DOS_SIGNATURE) {
            dr_fprintf(modules_file, "# Invalid DOS signature in %s: 0x%x\n", module_name, dos_header->e_magic);
            return;
        }
        
        IMAGE_NT_HEADERS *nt_headers = (IMAGE_NT_HEADERS *)(base + dos_header->e_lfanew);
        if (nt_headers->Signature != IMAGE_NT_SIGNATURE) {
            dr_fprintf(modules_file, "# Invalid NT signature in %s: 0x%x\n", module_name, nt_headers->Signature);
            return;
        }
        
        // Get export directory
        IMAGE_DATA_DIRECTORY *export_dir = &nt_headers->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT];
        if (export_dir->VirtualAddress == 0) {
            dr_fprintf(modules_file, "# No export directory found in %s\n", module_name);
            return;
        }
        
        IMAGE_EXPORT_DIRECTORY *exports = (IMAGE_EXPORT_DIRECTORY *)(base + export_dir->VirtualAddress);
        DWORD *name_array = (DWORD *)(base + exports->AddressOfNames);
        DWORD *addr_array = (DWORD *)(base + exports->AddressOfFunctions);
        WORD *ordinal_array = (WORD *)(base + exports->AddressOfNameOrdinals);
        
        for (DWORD i = 0; i < exports->NumberOfNames && i < 10000; i++) {
            char *func_name = (char *)(base + name_array[i]);
            
            if ((app_pc)func_name < base || (app_pc)func_name > mod->end) {
                continue;
            }
            
            WORD ordinal = ordinal_array[i];
            if (ordinal < exports->NumberOfFunctions) {
                DWORD func_rva = addr_array[ordinal];
                app_pc func_addr = base + func_rva;
                
                if (func_rva >= export_dir->VirtualAddress && 
                    func_rva < export_dir->VirtualAddress + export_dir->Size) {
                    dr_fprintf(modules_file, "%p %s!%s (forwarded)\n", func_addr, module_name, func_name);
                } else {
                    dr_fprintf(modules_file, "%p %s!%s\n", func_addr, module_name, func_name);
                }
            }
        }
    }
    __except(EXCEPTION_EXECUTE_HANDLER) {
        dr_fprintf(modules_file, "# Exception occurred during PE parsing of %s\n", module_name);
    }
    
#else
    dr_fprintf(modules_file, "# PE parsing only supported on Windows for %s\n", module_name);
#endif
}

static void enumerate_all_modules(void)
{
    dr_module_iterator_t *iter = dr_module_iterator_start();
    if (!iter) {
        dr_fprintf(modules_file, "# Failed to start module iterator\n");
        return;
    }
    
    int module_count = 0;
    while (dr_module_iterator_hasnext(iter)) {
        module_data_t *mod = dr_module_iterator_next(iter);
        if (mod) {
            module_count++;
            
            const char *module_name = dr_module_preferred_name(mod);
            if (!module_name) {
                module_name = mod->names.module_name;
            }
            if (!module_name) {
                module_name = "unknown";
            }
            
            dr_fprintf(modules_file, "Module %d: %s\n", module_count, module_name);
            
            enumerate_module_exports(mod, module_name);
            
            dr_free_module_data(mod);
        }
    }
    
    dr_module_iterator_stop(iter);
}

static void check_entry_point(app_pc addr)
{
    if (!modules_enumerated && main_entry_point && addr == main_entry_point) {
        dr_mutex_lock(mutex);
        if (!modules_enumerated) {
            modules_enumerated = true;
            enumerate_all_modules();
        }
        dr_mutex_unlock(mutex);
    }
}

static void log_instruction(app_pc addr)
{
    check_entry_point(addr);
    
    instr_t instr;
    instr_init(dr_get_current_drcontext(), &instr);
    
    app_pc next_pc = decode(dr_get_current_drcontext(), addr, &instr);
    
    if (next_pc != NULL) {
        char disasm_buf[256];
        instr_disassemble_to_buffer(dr_get_current_drcontext(), &instr, 
                                  disasm_buf, sizeof(disasm_buf));
        
        const char *module_name = get_module_name_for_address(addr);
        
        dr_mutex_lock(mutex);
        dr_fprintf(log_file, "%s!%p %s\n", module_name, addr, disasm_buf);
        dr_mutex_unlock(mutex);
    }
    
    instr_free(dr_get_current_drcontext(), &instr);
}

static dr_emit_flags_t event_app_instruction(void *drcontext, void *tag, instrlist_t *bb,
                                            instr_t *instr, bool for_trace, bool translating,
                                            void *user_data)
{
    if (instr_is_app(instr)) {
        dr_insert_clean_call(drcontext, bb, instr, (void *)log_instruction,
                           false, 1, OPND_CREATE_INTPTR(instr_get_app_pc(instr)));
    }
    
    return DR_EMIT_DEFAULT;
}

static void event_module_load(void *drcontext, const module_data_t *mod, bool loaded)
{
    if (loaded) {
        if (mod->start == dr_get_main_module()->start) {
            main_entry_point = mod->entry_point;
        }
    }
}

static void event_exit(void)
{
    dr_mutex_destroy(mutex);
    dr_close_file(log_file);
    dr_close_file(modules_file);
    
    drx_exit();
    drmgr_exit();
}

DR_EXPORT void dr_client_main(client_id_t id, int argc, const char *argv[])
{
    drmgr_init();
    drx_init();
    
    log_file = dr_open_file("instructions.log", DR_FILE_WRITE_OVERWRITE);
    if (log_file == INVALID_FILE) {
        dr_fprintf(STDERR, "ERROR: Cannot open instructions.log\n");
        return;
    }
    
    modules_file = dr_open_file("all_modules_functions.log", DR_FILE_WRITE_OVERWRITE);
    if (modules_file == INVALID_FILE) {
        dr_fprintf(STDERR, "ERROR: Cannot open all_modules_functions.log\n");
        dr_close_file(log_file);
        return;
    }
    
    mutex = dr_mutex_create();
    
    dr_register_exit_event(event_exit);
    drmgr_register_module_load_event(event_module_load);
    
    drmgr_register_bb_instrumentation_event(NULL, event_app_instruction, NULL);
    
    dr_fprintf(log_file, "# DynamoRIO Instruction Tracer Started\n");
    
    module_data_t *main_mod = dr_get_main_module();
    if (main_mod) {
        main_entry_point = main_mod->entry_point;
        dr_free_module_data(main_mod);
    }
    
    dr_log(NULL, DR_LOG_ALL, 1, "DynamoRIO enhanced module enumerator loaded\n");
}