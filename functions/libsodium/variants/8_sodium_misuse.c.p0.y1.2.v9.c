void sodium_misuse(void)
{
    void (*func_ptr)(void);

    (void) sodium_crit_leave();
    if (!sodium_crit_enter()) {
        func_ptr = _misuse_handler;
        if (func_ptr) {
            (*func_ptr)();
        }
    }
    /* LCOV_EXCL_START */
    abort();
}