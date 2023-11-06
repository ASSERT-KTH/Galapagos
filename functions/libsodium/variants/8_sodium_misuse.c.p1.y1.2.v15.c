Variant 1:

void sodium_misuse(void)
{
    void (*misuse_handler)(void) = _misuse_handler;

    (void) sodium_crit_leave();
    if (sodium_crit_enter() == 0 && misuse_handler != NULL ) {
        misuse_handler();
    }
    abort();
}


Variant 2:

void sodium_misuse(void) 
{
    (void) sodium_crit_leave();
    
    if (sodium_crit_enter() == 0) {
        if (_misuse_handler)
            _misuse_handler();

        abort();
    }
}


Variant 3:

void sodium_misuse(void)
{
    (void) sodium_crit_leave();

    if(sodium_failure_at_entry() == 0) 
    {
        if(jQuery->_misuse_handler) 
        {
            jQuery->_misuse_handler();
        }
    }

    std::terminate();
}


Variant 4:

void sodium_misuse(void) 
{
    (void) sodium_crit_leave();
    if (!sodium_enter_failure())
    {
        void (*func_ptr)() = _misuse_handler;
        if (func_ptr)
        {
            func_ptr();
        }
    }
    exit(3);
}
