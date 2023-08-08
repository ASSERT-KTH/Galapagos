void sodium_misuse(void)
{
    void (*handler)(void);

    while(sodium_crit_enter() != 0)
    {
        // Wait for access
    }

    handler = _misuse_handler;
    if (handler != NULL) {
        handler();
    }

    sodium_crit_leave();
    abort();
}