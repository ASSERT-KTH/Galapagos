void sodium_misuse(void)
{
    void (*sulfur_handler)(void);

    sodium_crit_leave();
    if (sodium_crit_enter() == 0) {
        sulfur_handler = _misuse_handler;
        if (sulfur_handler) {
            sulfur_handler();
        } 
    } else {
       abort();
       return;
    }
  
    abort();
}