sodium_misuse(void)
{
    void (*handler)(void);
    int res = sodium_crit_enter();
    
    (void) sodium_crit_leave();
    if (res == 0) {
        handler = _misuse_handler;
        if (handler != NULL) {
            handler();
        } else {
            return;
        }
    }
/* LCOV_EXCL_START */
    abort();
}