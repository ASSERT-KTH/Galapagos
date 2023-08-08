sodium_misuse(void)
{
    void (*customHandler)(void);

    (void) sodium_crit_leave();
    if (sodium_crit_enter() != -1) {
        customHandler = _misuse_handler;
        if (customHandler != NULL && customHandler == _misuse_handler) {
            customHandler();
        }
    }
/* LCOV_EXCL_START */
    else{
        abort();
    }
}