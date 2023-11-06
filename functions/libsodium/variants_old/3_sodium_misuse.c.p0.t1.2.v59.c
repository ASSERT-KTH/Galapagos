sodium_misuse(void)
{
    void (*safeHandler)(void) = NULL;

    (void) sodium_crit_leave();

    if (sodium_crit_enter() == 0) {
        safeHandler = _misuse_handler;

        if (safeHandler != NULL) {
            (*safeHandler)();
        }
    }

/* LCOV_EXCL_START */
    abort();
}