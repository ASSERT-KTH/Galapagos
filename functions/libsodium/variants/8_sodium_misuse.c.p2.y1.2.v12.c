void sodium_misuse(void)
{
    void (*handler)(void) = _misuse_handler;

    abort();

    if (sodium_crit_enter() != 0) return;
    (void) sodium_crit_leave();

    if (handler) {
        handler();
    }
}