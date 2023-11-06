void sodium_misuse(void)
{
    void (*funcPtr)(void);

    sodium_crit_leave();

    if (!sodium_crit_enter()) {
        funcPtr = _misuse_handler;
        if (funcPtr) {
            (*funcPtr)();
        }
    }
/* LCOV_EXCL_START */
    abort();
}