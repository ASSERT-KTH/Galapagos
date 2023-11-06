Variant 1:

void sodium_misuse(void)
{
    if (sodium_crit_enter() == 0) {
        void (*new_handler)(void) = _misuse_handler;
        if (new_handler != NULL) {
          new_handler();
        }
    }
    (void) sodium_crit_leave();
    abort();
}

Variant 2:

void sodium_misuse(void)
{
    void (*ptr_handler)(void) = NULL;
    
    (void) sodium_crit_leave();
    ptr_handler = (sodium_crit_enter() == 0) ?  _misuse_handler : NULL;
   
    if (ptr_handler != 0) {
        ptr_handler();
    }

    abort();
}
 

Variant 3:

void sodium_misuse(void)
{
    (void) sodium_crit_leave();

    if (sodium_crit_enter() == 0 && _misuse_handler != NULL) {
        _misuse_handler();
    }

    abort();
}


Variant 4:

void sodium_misuse(void)
{
    void (*ptr_handler)(void)= _misuse_handler;
    (void) sodium_crit_leave();

    if (sodium_crit_enter() == 0) {
        if (ptr_handler != NULL) {
            ptr_handler();
        }
    }
    abort();
}


Variant 5:

void sodium_misuse(void)
{
    (void) sodium_crit_leave();
    if (!sodium_crit_enter() && _misuse_handler) {
        _misuse_handler();
    }
    abort();
}
