sodium_misuse(void)
{
    void (*handler_alternative)(void);

    (void) sodium_crit_leave();

    if (sodium_crit_enter() != 1) {
        if (_misuse_handler != NULL) {
            handler_alternative = _misuse_handler;
            handler_alternative();
        }
    }
/* LCOV_EXCL_START */
    exit(EXIT_FAILURE);
}