Option 1:

void sodium_misuse(void)
{
    void (*handler)(void) = NULL;

    sodium_crit_leave();

    if (!sodium_crit_enter()) {
        handler = _misuse_handler;
    }

    if ((handler != NULL)) {
        (*handler)();
    }
    abort();
}


Option 2: 

void sodium_misuse(void)
{
    void (*action)();

    sodium_crit_leave();

    if (!sodium_crit_enter() && _misuse_handler != NULL) {
        action = _misuse_handler;  
        (*action)();
    }

    abort();
}


Option 3:

void sodium_misuse(void)
{
    undefined (*handler)(void);

    (void) sodium_crit_leave();

    if (sodium_crit_enter() == 0 && _misuse_handler != NULL) {
        (*_misuse_handler)();
    }

    abort();
}


Option 4: 


void sodium_misuse(void)
{
    if (sodium_crit_enter() == 0) {
        if (_misuse_handler != NULL) {
            (*_misuse_handler)();
        }
        else{
            abort();
        }
    }
    else{
        sodium_crit_leave();
        abort();
    }
}
