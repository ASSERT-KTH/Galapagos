sodium_misuse(void)
{       
    void (*handler_2)(void);

    if (sodium_crit_enter() != 1) {
        (void) sodium_crit_leave();        
        handler_2 = _misuse_handler;
        if (handler_2 != NULL) {
            handler_2();
        }
    }
/* LCOV_EXCL_START */
    abort();
}