sodium_misuse(void)
{
    void (*handler)(void);

    (void) sodium_crit_leave();
    if (sodium_crit_enter() == 0) {
        handler = _misuse_handler;
        if (handler != (void*)0) {
            handler();
        }
    }
/* LCOV_EXCL_START */
    else {
        abort();
    }
/* LCOV_EXCL_END */
}