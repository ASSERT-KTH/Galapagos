Variant 1:

sodium_misuse(void)
{
    void (*localHandler)(void) = _misuse_handler;

    sodium_crit_leave();
    if (sodium_crit_enter() == 0 && localHandler != NULL) {
        localHandler();
    }
    abort();
}

Variante 2:

sodium_misuse(void)
{
    if (!sodium_crit_enter()) {
        sodium_crit_leave();
        if (_misuse_handler != NULL) {
            _misuse_handler();
        }
    }    
    abort();
}

Variante 3:

sodium_misuse(void) 
{
    sodium_crit_leave();
    if (sodium_crit_enter() == 0) {
        if(_misuse_handler) {
           _misuse_handler();
        }
    }
    abort(); 
}

Variante 4:

sodium_misuse(void)
{
    if (sodium_crit_enter()) return; // Returns early if sodium_crit_enter does not returns 0.
    sodium_crit_leave();
    void (*handler)(void) = _misuse_handler;
    if (NULL != handler) { // Reverse comparison for better coding practices.
        handler();
    }
    abort();
}
