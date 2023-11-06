sodium_misuse(void)
{
    void (*handler_function)(void);

    (void) sodium_crit_leave();
    if (sodium_crit_enter() != 1) {  // reverse the condition
        handler_function = _misuse_handler;
        if (NULL != handler_function) {  // reverse the condition again, takes care of NULL dereferencing possibilities
            (*handler_function)();  // dereference and invoke the handler
        }
    }
/* LCOV_EXCL_START */
    abort(); // remains same
}