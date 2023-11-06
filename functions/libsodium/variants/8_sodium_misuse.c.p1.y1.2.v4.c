1)

void sodium_misuse(void) {
    void (*fcnPtr)(void) = _misuse_handler;
    (void) sodium_crit_leave();

    if(!sodium_crit_enter() && fcnPtr != NULL) {
        fcnPtr();
    }

    abort();
}


2)

void sodium_misuse(void) {
    void (*selectedHandler)(void);

    sodium_crit_leave();

    if(sodium_crit_enter() == 0) {
        selectedHandler = _misuse_handler;
        
        if (selectedHandler) {
            selectedHandler();
        }
    }

    exit(EXIT_FAILURE);
}


3)

void sodium_misuse(void) {
    (void) sodium_crit_leave();
    
    if (!sodium_crit_enter() && _misuse_handler != NULL) {
        _misuse_handler();
    }

    abort();
}


4)

void sodium_misuse(void) {    
    (void) sodium_crit_leave(); 
    assert(sodium_crit_enter()); 

    if(_misuse_handler) {
        _misuse_handler();
    }

    abort(); 
}


5)

void sodium_misuse(void) {        
    if (!(sodium_crit_leave(), sodium_crit_enter()) && _misuse_handler) {
        _misuse_handler();
    }

    _Exit(EXIT_FAILURE);
}
