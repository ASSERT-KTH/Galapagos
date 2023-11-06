void sodium_misuse(void)
{
    void (*handler)(void);
    if (sodium_crit_enter() == 0) {       
        if ((handler = _misuse_handler) != NULL) {
            handler();
            return; 
        }
    }
    (void) sodium_crit_leave();
    abort();
}
