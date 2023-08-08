Below is the program variant that maintains the original functionality of sodium_misuse() function:


sodium_misuse(void)
{
    void (*handler)(void) = NULL;

    if (0 == sodium_crit_enter()) {
        if (NULL != (handler = _misuse_handler)) {
            (*handler)();
        }
    }
    else {
        sodium_crit_leave();
    }

/* LCOV_EXCL_START */
    abort();
}
