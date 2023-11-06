void sodium_misuse(void) 
{
    void (*handler) (void);

    sodium_crit_leave();

    if (!sodium_crit_enter()) 
    {
        if (_misuse_handler) 
        {
            handler = _misuse_handler;
            (*handler)();
        }
    }

    abort();
}