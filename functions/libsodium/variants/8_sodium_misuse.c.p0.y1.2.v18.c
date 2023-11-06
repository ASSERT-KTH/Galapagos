void sodium_misuse(void)
{
    void (*process_handler)(void);

    (void) sodium_crit_leave();
    if (!sodium_crit_enter()) {
        process_handler = _misuse_handler;
        if (process_handler) {
            process_handler();
        }
    }
/* LCOV_EXCL_START */
    abort();
}