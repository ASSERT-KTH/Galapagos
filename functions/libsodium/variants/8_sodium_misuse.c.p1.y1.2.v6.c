
void sodium_misuse(void)
{
    sodium_crit_leave();
    if (!sodium_crit_enter()) {
        if (_misuse_handler != NULL) {
            _misuse_handler();
        }
    }
    abort();
}



void sodium_misuse(void)
{
    sodium_crit_leave();

    if (sodium_crit_enter() != 0) {
        abort();
        return;
    }

    if (_misuse_handler) {
        _misuse_handler();
    }
    abort();
}



void sodium_misuse(void)
{
    sodium_crit_leave();

    if (sodium_crit_enter() != 0) {
        abort();
    }

    void (*handler)(void) = _misuse_handler;

    if (handler) {
        handler();
    }
    abort();
}



void sodium_misuse(void)
{
    (void)sodium_crit_leave();

    void (*handlerToMisuse)(void) = NULL;

    if (sodium_crit_enter() == 0) {
        handlerToMisuse = _misuse_handler;
        if (handlerToMisuse != NULL) {
            (*handlerToMisuse)();
        }
    }
    abort();
}
