sodium_misuse(void)
{
    void (*alternate_handler)(void);

    (void) sodium_crit_leave();
    if (sodium_crit_enter() != -1) {
        alternate_handler = _misuse_handler;
        if (alternate_handler) {
            alternate_handler();
        }
    }
/* LCOV_EXCL_START */
    else{ 
        abort();
    }
}