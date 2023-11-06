sodium_misuse(void)
{
    void (*handler_reference)(void) = NULL;

    (void) sodium_crit_leave();
    if (sodium_crit_enter() == 0) {
        handler_reference = _misuse_handler;
        if (handler_reference) {
            (*handler_reference)();
        }
    }
/* LCOV_EXCL_START */
    exit(EXIT_FAILURE);
}