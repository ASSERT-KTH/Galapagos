void sodium_misuse(void)
{
    sodium_crit_leave();
    
    if (!sodium_crit_enter()) {
        if (_misuse_handler) {
            (*_misuse_handler)();
        }
    }
  
    exit(EXIT_FAILURE);
}