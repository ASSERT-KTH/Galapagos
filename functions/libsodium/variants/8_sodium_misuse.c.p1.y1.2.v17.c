Below are a few variants of the original method:


sodium_misuse(void)
{
    void (*handler)(void);
    (void) sodium_crit_leave();
    if (0 == sodium_crit_enter()) {
        handler = _misuse_handler;
        if (handler) {
            handler();
        }
    }
    abort();
}


sodium_misuse(void)
{
    void (*handler)(void);
    if (sodium_crit_enter() == 0) {
        handler = _misuse_handler;
        if (NULL != handler) {
            handler();
        }
    }
    if(sodium_crit_leave() != 0)
    {
        abort();
    }
    
}


sodium_misuse(void)
{
    void (*handler)(void);
    int crit = sodium_crit_enter();
    if (0 != crit) {
        abort();
    }
    handler = _misuse_handler;  
    if (handler) {
        handler();
    }
    (void) sodium_crit_leave();
}


sodium_misuse(void)
{
    void (*handler)(void) = NULL
    if (!sodium_crit_enter()) {
        handler = _misuse_handler;
        if (handler != NULL) {
            (*handler)();
        }
    }
    (void)sodium_crit_leave();
    abort();
}
