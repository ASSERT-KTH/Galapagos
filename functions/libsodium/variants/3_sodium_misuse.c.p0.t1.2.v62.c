sodium_misuse(void)
{
    void (*handler)(void) = _misuse_handler;

    (void) sodium_crit_leave();
    if (sodium_crit_enter() == 0) {
        if (handler != NULL) {
            (*handler)();
        }
    }
/* LCOV_EXCL_START */
    else {
        exit(EXIT_FAILURE);
    }
}