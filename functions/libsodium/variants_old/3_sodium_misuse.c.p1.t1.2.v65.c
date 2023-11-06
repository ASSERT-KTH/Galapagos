The following code variant maintains the functionality of the original method but with different control flow:


sodium_misuse(void)
{
    void (*handler)(void);

    if (sodium_crit_leave() == 0) {
        if (sodium_crit_enter() == 0) {
             handler = _misuse_handler;
             if (handler != NULL) {
                 handler();
             }
        }
        else {
            /* LCOV_EXCL_START */
            abort();
        }
    }
    else {
        /* LCOV_EXCL_START */
        abort();        
    }
}


This version of `sodium_misuse` checks the returns of `sodium_crit_leave` and `sodium_crit_enter` to decide whether to call `abort()`. In the original version, `abort()` is called unconditionally (aside from reaching the handled part of the pair of if clauses), while in this version `abort()` is only called if either `sodium_crit_leave` or `sodium_crit_enter` returns non-zero. Note, though, that this version may not strictly meet all purposes of the original depending on the specifies of `sodium_crit_leave()`. That part is called in the original before `sodium_crit_enter()` is tried and checked. That sequence is maintained here, but now with the "guarding" if introduced.