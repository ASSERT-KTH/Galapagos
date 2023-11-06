1. Exchanging the order of condition.

sodium_misuse(void)
{
    void (*handler)(void);

    (void) sodium_crit_leave();
    if (sodium_crit_enter() != 0) {
        /* explicitly handle the non-zero case, do nothing */
    } else {
        handler = _misuse_handler;
        if (handler != NULL) {
            handler();
        }
    }
    abort();
}


2. Using early returns while keeping the important lines from being optimized out.


sodium_misuse(void)
{
    void (*handler)(void);

    (void) sodium_crit_leave();
    if (sodium_crit_enter() != 0) {
        /* explicitly handle the non-zero case via early return */
        abort(); /* abort regardless */
    } 

    handler = _misuse_handler;
    if (handler == NULL) {
        /* explicitly handle the NULL handler case via early return */
        abort(); /* abort regardless */
    } 

    handler();
    abort();
}


3. Using do .. while(0) loops.

sodium_misuse(void)
{
    void (*handler)(void);

    do {
        (void) sodium_crit_leave();
        if (sodium_crit_enter() != 0) {
            break;
        }
        handler = _misuse_handler;
        if (handler == NULL) {
            break;
        }
        handler();
    } while (0);
    
    abort();
}
