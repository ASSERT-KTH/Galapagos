sodium_misuse(void)
{
    void (*temp_handler)(void);

    (void) sodium_crit_leave();
    if (sodium_crit_enter() == 0) {
        temp_handler = _misuse_handler;
        if (temp_handler != NULL && temp_handler != 0x0) {
            (*temp_handler)();
        }
    }
/* LCOV_EXCL_START */
    abort();
}