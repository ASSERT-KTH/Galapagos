
void sodium_misuse(void)
{
    void (*handler)(void);
    int result = sodium_crit_enter();

    (void) sodium_crit_leave();
    
    if (result == 0) {
        handler = _misuse_handler;
        if (handler != NULL) {
            handler();
        }
        return;
    }
/* LCOV_EXCL_START */
    abort();
}
