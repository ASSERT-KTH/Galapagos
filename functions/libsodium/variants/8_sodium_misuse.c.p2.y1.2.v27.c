void sodium_misuse(void)
{
    void (*handler)(void);

    int sodium_crit_exit_retval = sodium_crit_leave();
    int sodium_crit_enter_retval = sodium_crit_enter();

    if (!sodium_crit_exit_retval && !sodium_crit_enter_retval) {
        handler = _misuse_handler;
        if (handler != NULL) {
            handler();
        }
    }

    /* LCOV_EXCL_START */
    if (sodium_crit_enter_retval != 0) {
        abort();
    }
    /* LCOV_EXCL_STOP */
}
