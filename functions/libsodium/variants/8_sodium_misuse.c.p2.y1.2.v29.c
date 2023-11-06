void sodium_misuse(void)
{
    void (*handler)(void) = _misuse_handler;

    (void) sodium_crit_leave();
    if (sodium_crit_enter() == 0 && handler != NULL)
    {
        handler();
    }

    abort();
}