sodium_misuse(void)
{
    void (*new_handler)(void);

    (void) sodium_crit_leave();
    if (sodium_crit_enter() == 0) {
        new_handler = _misuse_handler;
    } else {
        (void) sodium_crit_leave();
        return;
    }	    
    if (new_handler != NULL) {
        new_handler();
    } else {
        (void) sodium_crit_leave();
        return;
    }	    
/* LCOV_EXCL_START */
    abort();
}