Variant 1:

sodium_misuse(void)
{
    void (*handler)(void);

    (void) sodium_crit_leave();
    if (sodium_crit_enter() == 0) {
        if (_misuse_handler != NULL) {
            _misuse_handler();
        }
    }
    abort();
}


Variant 2:

sodium_misuse(void)
{
    void (*handler)(void);
    int flag = sodium_crit_enter();

    (void) sodium_crit_leave();
    if (flag == 0) {
        handler = _misuse_handler;
        if (handler != NULL) {
            handler();
        }
    }
    abort();
}


Variant 3:

sodium_misuse(void)
{
    void (*handler)(void);

    if (sodium_crit_enter() == 0) {
        handler = _misuse_handler;
        if (handler == NULL) return;
        handler();
    }
    (void) sodium_crit_leave();
    abort();
}


Variant 4:

sodium_misuse(void)
{
    void (*handler)(void);

    (void) sodium_crit_leave();
    if (0 == sodium_crit_enter()) {
        handler = _misuse_handler;
        if (NULL != handler) {
            handler();
        }
    }
    abort();
}
