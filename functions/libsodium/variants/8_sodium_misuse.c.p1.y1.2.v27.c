Variant 1: Inline transfer of function content without conditional statement.

void sodium_misuse(void)
{
    (void) sodium_crit_leave();
    if (sodium_crit_enter() == 0 && _misuse_handler != NULL) {
        _misuse_handler();
    }
    abort();
}


Variant 2: Reverse the conditional statement to minimize nested logic.

void sodium_misuse(void) 
{
    (void) sodium_crit_leave();

    if (sodium_crit_enter() != 0) { 
        abort();
    }
    void (*handler)(void) = _misuse_handler;
    if (handler != NULL) {
        handler();
    }
    abort();
}


Variant 3: Reduce to a single line if statement.

void sodium_misuse(void)
{
    (void) sodium_crit_leave();
    if (sodium_crit_enter() == 0 && _misuse_handler != NULL) _misuse_handler();
    abort();
}
    

Variant 4: store the result of `sodium_crit_enter()` in a variable and then checked.
 C
void sodium_misuse(void)
{
    int n;
    void (*handler)(void);

    (void) sodium_crit_leave();

    n = sodium_crit_enter(); 
    if (n == 0){
        handler = _misuse_handler;
        if(handler != NULL) {
            handler();
        }
    }
    abort();
}


Variant 5: Without local variables and function call directly stored to `handler`.

void sodium_misuse(void)
{
    (void) sodium_crit_leave();
    if (sodium_crit_enter() == 0 && (_misuse_handler != NULL)) {
        (*_misuse_handler)();
    }
    abort();
}
