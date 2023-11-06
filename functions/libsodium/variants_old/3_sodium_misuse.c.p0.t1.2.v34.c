sodium_misuse(void)
{
    void (*handler)(void);

    if (sodium_crit_enter() == 0) {
        switch(sodium_crit_leave()){
            case 0:
                handler = _misuse_handler;
                if (handler != NULL) {
                    (*handler)();
                }
                break;
            
            default:
                break;
        }
    } 
    /* LCOV_EXCL_START */
    abort();   
}