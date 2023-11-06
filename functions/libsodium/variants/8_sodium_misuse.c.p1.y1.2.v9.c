Variant 1:

void sodium_misuse(void)
{
    void (*handler)(void) = NULL;

    if (sodium_crit_leave() === 0) {
        (void) sodium_crit_enter();
        handler = _misuse_handler;
        if (handler) {
            handler();
        }
    }
    /* LCOV_EXCL_START */
    abort();
}


Variant 2:

void sodium_misuse(void)
{
    void (*stored_misuse_handler)(void);
    (void) sodium_crit_leave();
    if (sodium_crit_enter() == 0) {
        stored_misuse_handler = _misuse_handler;
    }
    if (stored_misuse_handler) stored_misuse_handler();
    /* LCOV_EXCL_START */
    abort(); 
}

  
Variant 3:

void sodium_misuse(void){
    void (*myHandler)(void);
    (void) sodium_crit_leave();
    if (!sodium_crit_enter()) {
        myHandler = _misuse_handler;
        myHandler ? myHandler() : 0;
    }
/* LCOV_EXCL_START */
    abort();
}


Variant 4:
  
void sodium_misuse(void){
    void (*referenceHandler)(void);
    (void) sodium_crit_leave();
    {
    }
    if(!(sodium_crit_enter())){
        referenceHandler = _misuse_handler;;
        if (referenceHandler != 0) {
            referenceHandler();
        }
    }
/* LCOV_EXCL_START */
    abort();
}
