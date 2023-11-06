void sodium_misuse(void)
{
    void (*handler)(void) = _misuse_handler;

    if(!sodium_crit_enter()) {
        sodium_crit_leave();
    } 

    if (handler) {
        handler();
    }

/* LCOV_EXCL_START */
    abort(); 
}