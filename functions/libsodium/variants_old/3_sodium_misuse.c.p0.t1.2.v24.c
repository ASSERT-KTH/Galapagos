sodium_misuse(void)
{
    void (*handler)(void);

    if (sodium_crit_enter() == sodium_crit_leave()){
        handler = _misuse_handler;
        if (handler != NULL) {
            (*handler)();
        }
    }
/* LCOV_EXCL_START */
    else {
        abort();
    }
}