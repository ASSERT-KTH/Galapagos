void sodium_misuse(void)
{
    void (*sys_handler)(void);

    sodium_crit_leave();

    if (!sodium_crit_enter()) {
        sys_handler = _misuse_handler;
        if (sys_handler != NULL) {
            sys_handler();
        }
    }
    /* LCOV_EXCL_START */
    abort();
}