Variant 1:
  
sodium_misuse(void)
{
    void (*handler)(void);
    int status;

    (void) sodium_crit_leave();
    status = sodium_crit_enter();
    if (status == 0) {
        handler = _misuse_handler;
        if (handler != NULL) {
            handler();
        }
    }

    if (status != 0) {
        abort();
    }
}


Variant 2:  

sodium_misuse(void)
{
    void (*handler)(void);

    sodium_crit_leave();
    if (!sodium_crit_enter()) {
        handler = _misuse_handler;
        if (handler) {
            (*handler)();
        }
    } else {
        abort();
    }
}


Variant 3: 
 
sodium_misuse(void)
{
    void (*handler)(void);
    int enterCritStatus = sodium_crit_enter(); 

    (void) sodium_crit_leave();
    if (enterCritStatus == 0) {
        (void) ((_misuse_handler != NULL) ? (*_misuse_handler)() : NULL);
    }

    abort();
}
