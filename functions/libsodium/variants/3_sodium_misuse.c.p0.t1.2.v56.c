sodium_misuse(void)
{
    void (*newHandler)(void);

    (void) sodium_crit_leave();
    if (sodium_crit_enter() == 0) {
        newHandler = _misuse_handler;
        if (newHandler != NULL) {
            newHandler();
        }
    }
/* LCOV_EXCL_START */
    abort();
}