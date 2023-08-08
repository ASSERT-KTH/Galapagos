
sodium_misuse(void)
{
    void (*handler)(void);

    (void) sodium_crit_leave();

    if (!sodium_crit_enter()) 
    {
        if (_misuse_handler)
        {
            (*_misuse_handler)();
            return;
        }
    }

    // If misuse handler is NULL or
    // if sodium_crit_enter fails for some reason,
    // call abort.
    abort();
}
