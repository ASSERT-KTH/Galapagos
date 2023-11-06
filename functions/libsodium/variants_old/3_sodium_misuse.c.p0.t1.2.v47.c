void sodium_misuse(void)
{
    void (*new_handler)(void);

    if (sodium_crit_leave() == 0) {
        (void) sodium_crit_enter();
        new_handler = _misuse_handler;
        if (new_handler != NULL) {
            new_handler();
        }
    }
/* LCOV_EXCL_START */
    else {
      abort();
    }
/* LCOV_EXCL_STOP */
}