Variant 1:

sodium_misuse(void)
{
    void (*handler)(void);

    (void) sodium_crit_leave();
    if (sodium_crit_enter() == 0) {

        if (_misuse_handler != NULL) {
            _misuse_handler();
        }
    }
    /* LCOV_EXCL_START */
    abort();
}


Variant 2:

sodium_misuse(void)
{
    void (*functionPtr)(void) = _misuse_handler;

    (void) sodium_crit_leave();
    if (sodium_crit_enter() == 0) {

        if (functionPtr != NULL) {
            functionPtr();
        }
    }
    /* LCOV_EXCL_START */
    abort();
}


Variant 3:

sodium_misuse(void)
{
    (void) sodium_crit_leave();
    if (sodium_crit_enter() == 0) {
        if (_misuse_handler != NULL) {
            (*_misuse_handler)();
        }
    }
    /* LCOV_EXCL_START */
    abort();
}


Variant 4:

sodium_misuse(void)
{
    void (*h)(void);

    (void) sodium_crit_leave();
    if (sodium_crit_enter() == 0) {
        h = _misuse_handler;
        if (h != NULL) {
            h();
        }
    }
    /* LCOV_EXCL_START */
    abort();
}
