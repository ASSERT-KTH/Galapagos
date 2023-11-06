1. Swap statements variant


sodium_misuse(void)
{
    void (*handler)(void);

    (void) sodium_crit_leave();

    handler = _misuse_handler;
    if (sodium_crit_enter() == 0 && handler != NULL) {
        handler();
    }

    abort();
}

2. Combine conditional variant


sodium_misuse(void)
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

3. Refactor if at the level of the assignment 


sodium_misuse(void)
{
    void (*handler)(void) = _misuse_handler;
    (void) sodium_crit_leave();
    if (sodium_crit_enter() == 0 && handler != NULL) {
        handler();
    }
    abort();
}


4. Better usage of the handler 


sodium_misuse(void)
{
    void (*handler)(void) = _misuse_handler;
    (void) sodium_crit_leave();
    if (sodium_crit_enter() == 0) {
        (handler != NULL) ? handler() : abort();
    }
}
  

5. Simplified usage of if logic 


sodium_misuse(void)
{
    void (*handler)(void) = _misuse_handler;
    (void) sodium_crit_leave();
    if (!sodium_crit_enter() && handler) {
        handler();
    }
    abort();
}
