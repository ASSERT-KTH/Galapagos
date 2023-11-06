Variant 1:

sodium_misuse(void)
{
    void (*misuseHandler)(void);
    (void) sodium_crit_leave();
    if (!sodium_crit_enter()) {
        misuseHandler = _misuse_handler;
        if (NULL != misuseHandler) {
            (*misuseHandler)();
        }
    }
/* LCOV_EXCL_START */
    abort();
}

Variant 2:

sodium_misuse(void)
{
    void (*codeHandler)(void);
    sodium_crit_leave();
    if (!sodium_crit_enter()) {
        codeHandler = _misuse_handler;
        if(codeHandler){
            (*codeHandler)();
        }
    }
/* LCOV_EXCL_START */
    abort();
}

Variant 3:

sodium_misuse(void)
{
    void (*misuse)(void);
    (void) sodium_crit_leave();
    if (0 == sodium_crit_enter()) {
        misuse = _misuse_handler;
        if(misuse){
            misuse();
        }
    }
/* LCOV_EXCL_START */
    abort();
}

Variant 4:

sodium_misuse(void)
{
    void (*ptrHandler)(void);
    sodium_crit_leave();
    if (NULL == sodium_crit_enter()) {
        ptrHandler = _misuse_handler;
        if(ptrHandler)
            ptrHandler();
    }
/* LCOV_EXCL_START */
    abort();
}
