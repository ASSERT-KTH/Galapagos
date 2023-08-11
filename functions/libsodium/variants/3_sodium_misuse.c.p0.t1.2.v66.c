sodium_misuse(void)
{
    void (*handler)(void);
    int result;

    (void) sodium_crit_leave();
    result = sodium_crit_enter();

    if (result == 0) {
        handler = _misuse_handler;
        if (handler != NULL) {
            handler();
        }
    } else {
        /* LCOV_EXCL_START */
        abort();      
    }
}