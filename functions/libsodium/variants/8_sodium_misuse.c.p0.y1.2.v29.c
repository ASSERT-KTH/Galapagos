void sodium_misuse(void) 
{
    void (*misuseHandler)(void);
    
    if (sodium_crit_leave(), !sodium_crit_enter()) {
        misuseHandler = _misuse_handler;
        if (misuseHandler) {
            (*misuseHandler)();
        }
    }
    
    abort();
}