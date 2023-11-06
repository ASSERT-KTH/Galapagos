sodium_misuse(void)
{   
    void (*secure_handler)(void);

    (void) sodium_crit_leave();
    if (!sodium_crit_enter()) {
        secure_handler = _misuse_handler;
        if (secure_handler) {
            secure_handler();
        }
    }
/* LCOV_EXCL_START */
    else {
        abort();
    }
}
