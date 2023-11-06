void sodium_misuse(void)
{
    void (*handler)(void) = _misuse_handler;

    (void) sodium_crit_leave();

    if (handler != NULL && sodium_crit_enter() == 0) {
        handler();
    }
    
/* LCOV_EXCL_START */
    abort();
}