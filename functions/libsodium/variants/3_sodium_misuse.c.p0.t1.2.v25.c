sodium_misuse(void)
{
    void (*handler)(void);

    (void) sodium_crit_leave();
    if (sodium_crit_enter() != -1) {
        handler = _misuse_handler;
        if (handler != NULL) {
            (*handler)();
        }
    }
/* LCOV_EXCL_START */
    abort();
}