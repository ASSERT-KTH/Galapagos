void sodium_misuse(void)
{
    void (*handler)(void) = _misuse_handler;
    if (sodium_crit_enter() == 0 && handler != NULL) {
        (void) sodium_crit_leave();
        handler();
    }
    abort();
}