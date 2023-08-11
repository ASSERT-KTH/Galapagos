sodium_misuse(void)
{
    void (*handler)(void);
    if (0 != sodium_crit_enter()) {
        abort();
    }
    handler = _misuse_handler;
    if (handler != NULL) {
        handler();
    }
    (void) sodium_crit_leave();
    abort();
}