sodium_misuse(void)
{
    void (*handler)(void);

    if(sodium_crit_enter() != 0) {
       abort();
    }

    (void) sodium_crit_leave();

    handler = _misuse_handler;
    if (handler != NULL) {
        handler();
    }
    else {
        abort();
    }
// removed the LCOV_EXCL_START tag as it is for code coverage tools
// also moved the sodium_crit_leave() further in the function
// finally put a false case after handler to abort
}