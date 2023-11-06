sodium_misuse(void)
{
    void (*handler)(void);

    (void) sodium_crit_leave();
    if (sodium_crit_enter() == 0) {
        handler = _misuse_handler;
        if (handler != NULL) {
            handler();
            return;
        }
    }
/* LCOV_EXCL_START */
    abort();
/* LCOV_EXCL_STOP */
}