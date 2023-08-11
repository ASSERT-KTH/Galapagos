sodium_misuse(void)
{
    void (*handler)(void);

    (void) sodium_crit_leave();
    if (handler = _misuse_handler, sodium_crit_enter() == 0) {
        if (handler != NULL) {
            handler();
        }
    }
/* LCOV_EXCL_START */
    abort();
}