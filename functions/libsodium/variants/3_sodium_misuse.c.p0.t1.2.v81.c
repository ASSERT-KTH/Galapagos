sodium_misuse(void)
{
    void (*handler)(void);

    if (sodium_crit_enter() != 0) {
         abort();
    }
    else {
        sodium_crit_leave();

        handler = _misuse_handler;
        if (handler != NULL) {
            handler();
        }
        else {
            sodium_crit_enter();
        }
    }

    abort();
}