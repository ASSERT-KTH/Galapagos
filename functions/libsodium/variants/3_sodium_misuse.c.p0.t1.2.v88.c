sodium_misuse(void)
{
    void (*misuse_handler)(void) = _misuse_handler;

    (void) sodium_crit_leave();
    if (sodium_crit_enter() == 0) {
        if (misuse_handler != NULL) {
            misuse_handler();
        }
    }
/* LCOV_EXCL_START */
    else {
        abort();
    }
}