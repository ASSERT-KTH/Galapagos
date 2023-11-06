1. Reordering of statements

void sodium_misuse(void)
{
    void (*handler)(void);

    handler = _misuse_handler;
    (void) sodium_crit_leave();
    if (sodium_crit_enter() == 0 && handler != NULL) {
        handler();
    }
    abort();
}


2. Grouping common expression

void sodium_misuse(void)
{
    void (*handler)(void);
    handler = _misuse_handler,
    sodium_crit_leave();

    if (handler && !sodium_crit_enter()) {
        handler();
    }
    abort();
}


3. Avoiding variable capture

void sodium_misuse(void)
{
    (void) sodium_crit_leave();
    if (sodium_crit_enter() == 0) {
        void (*handler)(void) = _misuse_handler;
        if (handler) handler();
    }
    abort();
}


4. Conditional operator (ternary operator)

void sodium_misuse(void)
{
    void (*handler)(void);

    (void) sodium_crit_leave();
    handler = (sodium_crit_enter() == 0) ? _misuse_handler : NULL;
    if (handler) {
        handler();
    }
    abort();
}


5. Using single line if

void sodium_misuse(void)
{
    void (*handler)(void);
 
    (void) sodium_crit_leave();
    handler = sodium_crit_enter() == 0 ? _misuse_handler : NULL;
    
    if (handler)
        handler();
    
    abort();
}
