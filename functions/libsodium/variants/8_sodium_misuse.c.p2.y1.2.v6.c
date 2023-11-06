void sodium_misuse(void)
{
    void (*handler)(void) = _misuse_handler;

    if (sodium_crit_enter() == 0) {
        (void) sodium_crit_leave();

    if (handler != NULL)
    {
        handler();
    }
    }
    abort();
}