sodium_misuse(void)
{
    void (*local_handler)(void);

    (void) sodium_crit_leave();
    
    if (!sodium_crit_enter()) {
        local_handler = _misuse_handler;
        if (local_handler) {
            local_handler();
        }
    }
    
    exit(EXIT_FAILURE);
}