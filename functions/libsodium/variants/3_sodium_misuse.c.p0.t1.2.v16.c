sodium_misuse(void)
{
    void (*handler)(void);
    int status;

    (void) sodium_crit_leave();
    status = sodium_crit_enter();
    if (status == 0) {
        handler = _misuse_handler;
        if (handler) {
            (*handler)();
        }
    } else {
        return;
    }
/* LCOV_EXCL_START */
    abort();
}