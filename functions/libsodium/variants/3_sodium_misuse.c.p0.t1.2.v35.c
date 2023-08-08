sodium_misuse(void)
{
    void (*handler)(void) = NULL;
    
    (void) sodium_crit_leave();
    if (sodium_crit_enter() != 0) {
        abort();
    }

    handler = _misuse_handler;

    if (handler == NULL) {
        abort();
    }

    handler();
/* LCOV_EXCL_START */
    // No need to call abort since the if-statement guarantees handler is not null
}