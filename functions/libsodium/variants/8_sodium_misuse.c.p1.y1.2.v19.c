Variant 1:

sodium_misuse(void)
{
    void (*handler)(void) = _misuse_handler;

    (void) sodium_crit_leave();
    if (sodium_crit_enter() == 0 && handler != NULL) 
    {
        handler();
    }
    abort();
}


Variant 2:

sodium_misuse(void)
{
    (void) sodium_crit_leave();
    if (sodium_crit_enter() == 0) {
        if (_misuse_handler != NULL) {
            _misuse_handler();
        }
    }
    abort();
}


Variant 3:

sodium_misuse(void)
{
    void (*handler)(void);

    if (!sodium_crit_leave() && !sodium_crit_enter()) 
    {
        handler = _misuse_handler;
        if (handler) 
        {
            handler();
        }
    }     
    abort();
}


Variant 4:

sodium_misuse(void)
{
    void (*handler)(void);

    handler = _misuse_handler;

    if(sodium_crit_enter() == 0 && sodium_crit_leave() == 0)
    {
        if(handler)
            handler();
    }
    
    abort();
}
