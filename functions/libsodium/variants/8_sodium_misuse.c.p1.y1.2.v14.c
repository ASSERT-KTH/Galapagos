Variant 1:

void sodium_misuse(void)
{
    if (!sodium_crit_enter()) {
        if (_misuse_handler != NULL) {
            _misuse_handler();
        }
    }
    sodium_crit_leave();
    abort();
}


Variant 2:

void sodium_misuse(void)
{
    if (0 == sodium_crit_enter()) {
        void (*handler)(void) = _misuse_handler;
        if (NULL != handler) {
            (*handler)();
        }
    }
    sodium_crit_leave();
    abort();
}


Variant 3:

void sodium_misuse(void)
{
    sodium_crit_leave();
    if (sodium_crit_enter() == 0 && _misuse_handler) {
        _misuse_handler();
    }
    abort();
}


Variant 4:

void sodium_misuse(void)
{
    void (*local_handler)(void) = NULL;

    sodium_crit_leave();
    if (!sodium_crit_enter())
    {
        local_handler = _misuse_handler;
        if(local_handler)  
            local_handler();
    }
    abort();
}
