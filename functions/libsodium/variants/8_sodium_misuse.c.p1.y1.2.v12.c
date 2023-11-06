Variant 1:

sodium_misuse(void)
{
    void (*handler)(void) = _misuse_handler;

    (void) sodium_crit_leave();
    if (0 == sodium_crit_enter()) {
        
        if (NULL != handler) {
            (*handler)();
        }
    }
  
    abort();
}


Variant 2:

sodium_misuse(void)
{
    void (*handler)(void) = NULL;

    (void) sodium_crit_leave();
    if (! sodium_crit_enter()) {

        handler = _misuse_handler;        
        if (handler) {
            (*handler)();
        }
    }
   
    abort();
}


Variant 3:

sodium_misuse(void)
{
    void (*handler)(void);

    sodium_crit_leave();
    if (sodium_crit_enter() == 0) {

        handler = _misuse_handler;       
        if (handler) {
            (*handler)();
        }
    }
    
    abort();
}
    

Variant 4:

sodium_misuse(void)
{
    void (*handler)(void) = _misuse_handler;

    (void) sodium_crit_leave();
    if (!sodium_crit_enter()) {

        if (handler) {
            (*handler)();
        }
    }
  
    abort();
}
