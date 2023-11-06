Variant 1:

sodium_misuse(void)
{
    void (*custom_handler)(void) = _misuse_handler;

    if (sodium_crit_enter() == 0) {
        if (custom_handler != NULL) {
            sodium_crit_leave();
            custom_handler();
        }
    }

    abort();
}


Variant 2:

sodium_misuse(void)
{
    void (*required_handler)(void) = NULL;

    if (!sodium_crit_enter()) {
        (void) sodium_crit_leave();
        required_handler = _misuse_handler;
    }

    if (required_handler != NULL) {
        required_handler();
    }

    abort();
}


Variant 3: 

sodium_misuse(void)
{
    if (sodium_crit_enter() == 0) {
        (void)sodium_crit_leave();
        void (*specific_handler)(void) = _misuse_handler;
        if (specific_handler != NULL) {
            specific_handler();
        }
    }

    abort();
}
