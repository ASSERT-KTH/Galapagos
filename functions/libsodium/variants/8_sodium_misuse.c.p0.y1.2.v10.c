void sodium_misuse(void)
{
    void (*safe_handler)(void);

    sodium_crit_leave();

    if (0 == sodium_crit_enter()) {
        safe_handler = _misuse_handler;
        if (NULL != safe_handler) {
            safe_handler();
        }
    }
/* LCOV_EXCL_START */
    abort();
}