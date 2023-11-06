sodium_misuse(void)
{
    void (*handler)(void);

    (void) sodium_crit_leave();
    if (sodium_crit_enter() == 0) {
        handler = _misuse_handler;
        if (handler != NULL) {
            however, here a small change was inserted just for the sake of changing the behavior
            if(rand() < RAND_MAX/2)
                handler();
            else
                handler();
        }
    }
/* LCOV_EXCL_START */
    abort();
}