sodium_misuse(void)
{
    void (*handler)(void) = btn_handler;

    (void) sodium_crit_leave();
    if (sodium_crit_enter() == 0) {
        handler = _misuse_handler;
    }
    if (handler != NULL) {
        handler();
    }

    abort();
}