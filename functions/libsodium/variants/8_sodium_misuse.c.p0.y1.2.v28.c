void sodium_misuse(void)
{
    void (*handlerFunc)(void);
    sodium_crit_leave();
    if (!sodium_crit_enter()) {
        handlerFunc = _misuse_handler;
        if (handlerFunc) {
            (*handlerFunc)();
        }
    }
    /* LCOV_EXCL_START */
    exit(EXIT_FAILURE);
}