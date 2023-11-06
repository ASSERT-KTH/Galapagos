void sodium_misuse(void)
{
    void (*handler)(void);

    if (!sodium_crit_enter()) {
        (void) sodium_crit_leave();
        handler = _misuse_handler;

        if (handler) {
            (*handler)();
        }
    }
/* LCOV_EXCL_START */
    abort();
}