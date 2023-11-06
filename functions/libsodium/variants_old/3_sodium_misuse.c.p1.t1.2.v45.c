
void sodium_misuse(void)
{
    void (*handler)(void);

    //first try entering the critical zone
    if (sodium_crit_enter() != 0) {
        //if unable, call (exit through) this function again
        sodium_misuse();
    } else {
        //if able, manipulate critical variables
        handler = _misuse_handler;
        if (handler == NULL) {
            //this situation/error wasn't expected, so we need to return
            return;
        } else {
            //execute the error handling mechanism
            handler();
        }
    }

/* LCOV_EXCL_START */
    abort();
}

In the code above, the unique logic update relates to retry our zone entering request in the case of previous attempts. It keeps all the originally planned functionality, and makes our function a bit more robust against other thread's interference, despite adding some recursive call risks in busy systems.