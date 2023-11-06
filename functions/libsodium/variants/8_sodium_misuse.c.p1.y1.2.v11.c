Variant 1:

void sodium_misuse(void)
{
    void (*handler)(void) = _misuse_handler;
    (void) sodium_crit_leave();

    if (sodium_crit_enter() == 0 && handler != NULL) {
        handler();
    }

    abort(); // LCOV_EXCL_START
}


Variant 2:


void sodium_misuse(void)
{
    (void) sodium_crit_leave();
    if (sodium_crit_enter() == 0) {
        if (_misuse_handler != NULL) {
            _misuse_handler();
        }
    }
    abort(); // LCOV_EXCL_START
}


Variant 3:

void sodium_misuse(void)
{
    void (*h_func)(void);

    if (!sodium_crit_leave() && !sodium_crit_enter()) {
        h_func = _misuse_handler;
        if (h_func != NULL) {
            h_func();
        }
    } 

    abort(); // LCOV_EXCL_START
}


Variant 4:


void sodium_misuse(void)
{
    (void) sodium_crit_leave();

    if (!sodium_crit_enter() && _misuse_handler != NULL) {
        _misuse_handler();
    }

    abort(); // LCOV_EXCL_START
}
