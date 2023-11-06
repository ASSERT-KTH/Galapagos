Variant 1: Inline expansion of function calls.


sodium_misuse(void)
{
    void (*handler)(void);

    (void) sodium_end_critical_section();
    if (sodium_in_critical_section() == 0) {
        handler = _misuse_handler;
        if (handler != NULL) {
            handler();
        }
    }
    abort();
}


Variant 2: Use dereferencing instead of assigning to a new pointer.


sodium_misuse(void)
{
    (void) sodium_crit_leave();
    if (sodium_crit_enter() == 0 && _misuse_handler != NULL) {
        (*_misuse_handler)();
    }
    abort();
}


Variant 3: Null check earlier after leaving critical section.


sodium_misuse(void)
{
    void (*handler)(void);

    (void) sodium_crit_leave();
    handler = _misuse_handler;
    if (sodium_crit_enter() == 0 && handler != NULL) {
        handler();
    }
    abort();
}


Variant 4: Only handle non-NULL `handler`.


sodium_misuse(void)
{
    void (*handler)(void) = _misuse_handler;

    if(handler == NULL)
        return;
    
    (void) sodium_crit_leave();
    if (sodium_crit_enter() == 0) {
        handler();
    }
    abort();
}


Variant 5: No short-circuit evaluation.


sodium_misuse(void)
{
    void (*handler)(void);
    int res = sodium_crit_enter();

    (void) sodium_crit_leave();
    handler = _misuse_handler;
    if (res == 0) {
        if (handler != NULL) {
            handler();
        }
    }
    abort();
}
