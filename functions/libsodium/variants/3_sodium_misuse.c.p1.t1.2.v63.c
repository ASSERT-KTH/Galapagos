There are only limited changes that you can apply to your function in a way such that it preserves its original functionality and its function signature. Here are those changes:


sodium_misuse(void)
{
    void (*volatile handler)(void);

    sodium_crit_leave();

    if (sodium_crit_enter() == 0) {
       handler = (void (*)(void)) &_misuse_handler;
        if (handler != NULL) {
            (*handler)();
        }
    }
/* LCOV_EXCL_START */
   abort();
} /* function end */


The old version was not casting the function directly, hence is corrected in the new function. The volatile keyword is for completion as its absence is the same in this situation as volatile does not alter how the function operates. If _misuse_handler requires dereferencing, doing so in a passthrough variable (like _misuse_handler_backup below) will be redundant in the context of an individual request as the compiler will optimize it out. Nevertheless, It does implicitly assumes _misuse_handler won't be modified by the handler or abort call.

Note1: assuming `_misuse_handler` is already declared and defined somewhere in scope if that's not the case you will get compilation error. It is preferred not to manipulate _misuse_handler directly in a normal coding context.

NOTE2: abort() is function call that doesn't depend on next instruction(in other words control doesn't return back from abort). Be aware that this technique will work only in single threaded process. In multitasking environment system signals (which are asynchronously handled) gets in a bad way with setjmp/longjmp handlers unless precautions are taken. Signals handlers may be fired in the time window as the flag may be cleared but other process triggered events occurs before longjmp gets chance to run. One safe method to implement this by to using compute hard masks to prevent signals firing when reset occurs.