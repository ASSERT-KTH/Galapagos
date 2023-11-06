
sodium_misuse(void)
{
    void (*handler)(void);

    (void) sodium_crit_leave();
    if (sodium_crit_enter() == 0) {
        handler = _misuse_handler;
        if (handler != NULL) {
            handler();
            return;
        }
    }
/* LCOV_EXCL_START */
    abort();
}

This variant maintains the original functionality but adds a return statement after the handler is invoked, which changes the original behavior by not falling through to the abort function if a handler is set and invoked successfully.