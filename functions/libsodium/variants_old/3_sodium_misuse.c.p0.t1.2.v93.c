sodium_misuse(void)
{
    void (*new_handler)(void) = NULL;

    (void) sodium_crit_leave();
   
    if (sodium_crit_enter() == 0) {
        new_handler = _misuse_handler;
        if (new_handler) {
            new_handler();
        }
    }
    if(!new_handler){
       abort();  
    }
}