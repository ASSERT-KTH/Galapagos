sodium_misuse(void)
{
    void (*handler)(void) = NULL;

    if (sodium_crit_enter() == 0) {
        sodium_crit_leave();
        handler = _misuse_handler;
        if (handler) {
            handler();
        }
    }
/* LCOV_EXCL_START */
    else {
        abort();
    }
/* LCOV_EXCL_STOP */
    abort();
}