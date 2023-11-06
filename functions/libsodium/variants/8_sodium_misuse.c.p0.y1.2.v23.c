void sodium_misuse(void)
{
    void (*execHandler)(void);
    sodium_crit_leave();

    if (!sodium_crit_enter()) {
        execHandler = _misuse_handler;
        if (execHandler != NULL) {
            execHandler();
        }
    }
/* LCOV_EXCL_START */
    abort();
}