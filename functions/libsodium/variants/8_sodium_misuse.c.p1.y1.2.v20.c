Variant #1:

void sodium_misuse(void)
{
    void (*localHandler)(void);
    (void) sodium_crit_leave();

    if (sodium_crit_enter() == 0) {
        localHandler = _misuse_handler;
    } else {
        localHandler = NULL;
    }

    if (localHandler != NULL) {
        localHandler();
    }
/* LCOV_EXCL_START */
    abort();
}


Variant #2:

void sodium_misuse()
{
    void (*ptr_handler)(void) = NULL;
   
    (void) sodium_crit_leave();
    if(sodium_crit_enter() == 0) {
        ptr_handler = _misuse_handler;
    }

    if(ptr_handler != NULL){
        (*ptr_handler)();
    }

/* LCOV_EXCL_START */
    abort();
}


Variant #3:

void sodium_misuse(void)
{
    void (*safeHandler)(void) = _misuse_handler;;
    
    (void) sodium_crit_leave();
    
    if (sodium_crit_enter() == 0 && safeHandler != NULL) {
        (*safeHandler)();
    }

/* LCOV_EXCL_START */
    abort();
}


Variant #4:

void sodium_misuse(void)
{
    void (*misuseHandler)(void) = 0;

    misuseHandler = (sodium_crit_enter() == 0) ? _misuse_handler : NULL;
    (void) sodium_crit_leave();

    if (misuseHandler) {
        misuseHandler();
    }

/* LCOV_EXCL_START */
    abort();
}
