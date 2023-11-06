Here is a variant of the original function:


sodium_misuse(void)
{
    void (*handler)(void);

    (void) sodium_crit_leave();
    if (sodium_crit_enter() == 1) {
        if (handler = _misuse_handler) {
            (*handler)();
        }
    }
/* LCOV_EXCL_START */
    else {
        abort();
    }
}


While the original function will eventually abort regardless of `sodium_crit_enter()`'s return value or if `_misuse_handler` is non-null, this variant only aborts when `sodium_crit_enter()` returns something different from 1.

In both cases, `_misuse_handler` is run, if it's non-null, after an artificial "race condition" is introduced by leaving critical section (`sodium_crit_leave()`) and finally re-entering it (`sodium_crit_enter()`).