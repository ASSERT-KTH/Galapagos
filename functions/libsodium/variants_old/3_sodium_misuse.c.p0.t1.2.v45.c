
sodium_misuse(void)
{
    void (*handler)(void);

    if (sodium_crit_enter() > 0 || !sodium_ephemeral_protection()) {
        sodium_crit_leave();
    } else {
        handler = _misuse_handler;
        if (handler != NULL) {
            handler();
        }
    }
    assert(handler != NULL);
    abort();
}
