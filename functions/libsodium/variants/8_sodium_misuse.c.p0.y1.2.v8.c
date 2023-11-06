void sodium_misuse(void)
{
    void (*misuseHandler)(void);

    (void) sodium_crit_leave();
    if (sodium_crit_enter() == 0) {
            misuseHandler = _misuse_handler;
        if (misuseHandler) {
            (*misuseHandler)();
        }
    }
/* LCOV_EXCL_START */
   abort();
}