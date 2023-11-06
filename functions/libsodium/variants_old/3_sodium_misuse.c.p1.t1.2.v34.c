Here's how you might modify the function. I am assuming variables globally.

sodium_misuse(void)
{
    void (*handler)(void);
    static int rerun_abord = 1;

    (void) sodium_crit_leave();
    if(sodium_crit_enter() == 0 && rerun_abord){
        handler = _misuse_handler;
        if(handler != NULL) {
            handler();
        }
        rerun_abord = 0;
    }
	if (rerun_abord) { // Execute this instruction once.
/* LCOV_EXCL_START */
        abort();
/* LCOV_EXCL_STOP */
    }
}

In this variant, I modified the function by using a reactive programming pattern. The local static variable `rerun_abord` is initialized only once. It is paired with `abort()` to allow rerun or abort once. The use of a local [persistent] variable supports volatile situations where the functional/execution state demands. Among other things, this tends to optimize for runtime efficiency.