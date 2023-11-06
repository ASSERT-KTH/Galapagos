void sodium_misuse(void)
{
    void (*critical_handler)(void);
    
    if (!sodium_crit_enter()) {
        critical_handler = _misuse_handler;
        if (critical_handler) {
            critical_handler();
        }
    }
/* LCOV_EXCL_START */
    sodium_crit_leave();
    abort();
}