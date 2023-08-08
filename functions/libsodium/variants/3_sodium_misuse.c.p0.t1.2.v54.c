sodium_misuse(void)
{
    void (*handler)(void) = NULL;
    if (sodium_crit_enter() != 0) {
        abort();
    }
    sodium_crit_leave();
    handler = _misuse_handler;
    if (handler == NULL) {
        abort();
    }
    handler();
}