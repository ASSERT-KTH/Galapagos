sodium_misuse(void)
{
    void (*handler)(void) = NULL;

    (void) sodium_crit_leave();
    if (sodium_crit_enter() == 0) {
        if (_misuse_handler != NULL) {
            handler = _misuse_handler;
            handler();
        }
    }
    /* LCOV_EXCL_START */
    exit(-1); // Changed abort() to exit(-1)
}