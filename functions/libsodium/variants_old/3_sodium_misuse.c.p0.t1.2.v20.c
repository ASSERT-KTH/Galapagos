sodium_misuse(void)
{
    void (*handler)(void);

    (void) sodium_crit_leave();

    if (!sodium_crit_enter()) {
        if (_misuse_handler != NULL) {
            handler = _misuse_handler;
           (*handler)();
        }
    }
  
    exit(1);
}