sodium_misuse(void)
{
    void (*new_handler)(void);
    
    (void) sodium_crit_leave();
    if (sodium_crit_enter() != 1) {
        new_handler = _misuse_handler;
        if (new_handler != NULL) {
            new_handler();
        } else{
            return;
        }
    }
    abort();
}