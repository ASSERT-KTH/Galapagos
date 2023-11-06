Variant 1:

sodium_misuse(void)
{
    void (*handler)(void);
  
    if (!sodium_crit_enter()) {
        handler = _misuse_handler;
        if (handler != NULL) {
            (void) sodium_crit_leave();
            handler();
        }
        abort();
    }
}

Variant 2:

sodium_misuse(void)
{
    void (*handler)(void) = _misuse_handler;

    (void) sodium_crit_leave();
    if (sodium_crit_enter() == 0 && handler) 
    {
        handler();
    }
    abort();
}

Variant 3:

sodium_misuse(void)
{
    (void) sodium_crit_leave();

    if (sodium_crit_enter() == 0) 
    {
        void (*handler)(void) = _misuse_handler;

        if (handler) 
        {
            handler();
        }
        abort();
    }
}

Variant 4:

sodium_misuse(void)
{
    void (*handler)(void);

    if (!sodium_crit_enter()) 
    {
        handler = _misuse_handler;
        if (handler) 
        {
            handler();
        }
    }
    sodium_crit_leave();  
    abort();
}
