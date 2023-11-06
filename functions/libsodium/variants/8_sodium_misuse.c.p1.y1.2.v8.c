Variant 1:

void sodium_misuse() {
    void (*function_handler)(void);

    if (function_handler = _misuse_handler, sodium_crit_enter() == 0) {
        (void) sodium_crit_leave();
        if (function_handler) {
            function_handler();
        }
    }
                
    abort();
}


Variant 2:

void sodium_misuse() {
    void (*handler)(void) = _misuse_handler;
    sodium_crit_leave();

    if (sodium_crit_enter() == 0 && handler != NULL) {
        handler();
    }

    abort();
}


Variant 3:
 
void sodium_misuse(void) {
    void (*local_handler)(void) = _misuse_handler;
    if(!sodium_crit_leave() && !sodium_crit_enter() && local_handler)
        local_handler();

    abort();
}

Variant 4:

void sodium_misuse(void) {
    sodium_crit_leave();

    if (!sodium_crit_enter() && _misuse_handler != NULL) {
        _misuse_handler();
    }

    abort();
}   


Variant 5:

void sodium_misuse(void) {
    (void) sodium_crit_leave();

    if (sodium_crit_enter() == 0) {
        if (_misuse_handler != NULL) {
            _misuse_handler();
        }
    }

    abort();
}
