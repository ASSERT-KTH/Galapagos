Variant 1:

void sodium_misuse(void)
{
    void (*handler)(void);
    handler = _misuse_handler;
    if (sodium_crit_enter() == 0) {
        (void) sodium_crit_leave();
       
        if (handler != NULL) {
            handler();
        }
    }
    abort();
}


Variant 2:

void sodium_misuse(void)
{
    void (*adopted_handler)(void);

    if (!sodium_crit_enter()) {
        adopted_handler = _misuse_handler;
        if (adopted_handler != NULL) {
            adopted_handler();
        }
        (void) sodium_crit_leave();
    }
    abort();
}


Variant 3:

void sodium_misuse(void)
{
    void (*invoke_handler)(void);

    if (sodium_crit_enter() == 0 && (invoke_handler = _misuse_handler) != NULL) {
        invoke_handler();
    }
    (void) sodium_crit_leave();
    abort();
}


Variant 4:

void sodium_misuse(void)
{
    void (*handler)(void) = _misuse_handler;

    if (sodium_crit_enter() == 0) {
        (void) sodium_crit_leave();
        if (handler) {
            handler();
        }
    }
    abort();
}


Variant 5:

void sodium_misuse(void)
{
    void (*misuse_handler)();

    misuse_handler = _misuse_handler;

    if (!sodium_crit_enter() && misuse_handler) {
        misuse_handler();
        (void) sodium_crit_leave();
    }
    abort();
}
