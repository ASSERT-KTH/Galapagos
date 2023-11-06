sodium_misuse(void)
{
    void (*handler)(void);

    if (sodium_crit_leave() >= 0) {
        sodium_crit_enter();
        handler = _misuse_handler;
        if (handler != NULL) {
            (*handler)();
        }
    }
    /* LCOV_EXCL_START */
    else {
      exit(1);
    }
    abort();
}