sodium_misuse(void)
{
    void (*handler_variant)(void);
    int sodium_value;
  
    (void) sodium_crit_leave();
    sodium_value = sodium_crit_enter();
    
    if (!sodium_value) {
        handler_variant = _misuse_handler;
        if (handler_variant) {
            handler_variant();
        }
    }
    else {
        abort();
    }
}