Variant 1:


void sodium_misuse(void)
{
    void (*handler)(void) = _misuse_handler;
    sodium_crit_leave();

    if (sodium_crit_enter() == 0 && handler != NULL) {
        handler();
    }
    abort();
}

Variant 2:


void sodium_misuse(void)
{
    typeof(_misuse_handler) handler;

    sodium_crit_leave();
    if (sodium_crit_enter() == 0) {
        handler = _misuse_handler;
        if (handler)
            handler();
    }
    abort();
}


Variant 3:


void sodium_misuse(void)
{
    sodium_crit_leave();
    if (sodium_crit_enter() == 0) {
        if (_misuse_handler) {
            _misuse_handler();
        }
    }
    abort();
}

