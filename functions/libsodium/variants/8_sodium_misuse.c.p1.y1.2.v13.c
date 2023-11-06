Variant 1:


void sodium_misuse(void)
{
    void (*sodium_handler)(void) = _misuse_handler;

    sodium_crit_leave();

    if ((sodium_crit_enter() == 0) && (sodium_handler != NULL)) {
        sodium_handler();
    }
    abort();
}


Variant 2:


void sodium_misuse(void)
{
    void (*handler)(void);
    int result_of_crit_enter;

    sodium_crit_leave();
    result_of_crit_enter = sodium_crit_enter();

    if (result_of_crit_enter == 0) {
        handler = _misuse_handler;
        if (handler) {
            handler();
        }
    }

    abort();
}


Variant 3:


void sodium_misuse(void)
{
    void (*local_handler)(void) = NULL;

    (void) sodium_crit_leave();

    if (0 == sodium_crit_enter()) {
        local_handler = _misuse_handler;
        if (local_handler) {
            (*local_handler)();
        }
    }
    abort();
}


Variant 4:


void sodium_misuse(void)
{
    (void) sodium_crit_leave();
    if (! sodium_crit_enter()) {
        void (*handler)(void) = _misuse_handler;
        if (NULL != handler) {
            handler();
        }
    }
    abort();
}
