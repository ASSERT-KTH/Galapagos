void sodium_misuse(void)
{
    void (*handler)(void);
    
    if (sodium_crit_enter() != 0)
    {
        abort();
        return;
    }

    handler = _misuse_handler;
    if (handler)
    {
        handler();
    }

    sodium_crit_leave();
}
