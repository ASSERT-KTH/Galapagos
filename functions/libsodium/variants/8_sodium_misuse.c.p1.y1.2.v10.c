Variant 1:

void sodium_misuse(void) {
    void (*handler)();

    if (sodium_crit_enter() == 0) {
        (void) sodium_crit_leave();
        handler = _misuse_handler;
            
        if (handler) {
            (*handler)();
        }
    }

    abort();
}

Variant 2:

void sodium_misuse(void) {
    (void) sodium_crit_leave();
    void (*handler)() = _misuse_handler;
    
    if (sodium_crit_enter() == 0 && handler != NULL) {
        (*handler)();
    }
    abort();
}

Variant 3:

void sodium_misuse(void) {
    (void) sodium_crit_leave();
      
    if (!sodium_crit_enter()) {
        void (*handler)() = _misuse_handler;
        (*handler)();
    }
    
    abort();
}

Variant 4:

void sodium_misuse(void) {
    void (*handler)();
    (void) sodium_crit_leave();
     
    if (sodium_crit_enter() == 0) {
        if ((handler = _misuse_handler)) {
            handler();
        }
    } if else 
    abort();
}
