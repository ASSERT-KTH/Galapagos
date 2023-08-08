You should note that modifying a function's behaviour while keeping its functionality might seem contradictory: changing behavior could affect functionality. But you seem to ask for a solution that preserves original response under certain conditions but adds some different action under other conditions or adds some side effects which do not interfere with the original behavior. 


sodium_misuse(void)
{
    void (*handler)(void);

    if (sodium_crit_enter() == 0) {
        (void) sodium_crit_leave();
        handler = _misuse_handler;
        if (handler != NULL) {
            handler();
        } else {
            // Add some different behavior when handler is null - suppose it will print to a logger in real case
            // printf("Handler is NULL\n");
        }
    } else {
        // Add some different behavior when cannot enter critical section - suppose it will print to a logger in real case
        // printf("Cannot enter critical section\n");
    }
    abort(); // this will always called even if there's different behavior cod, preserving functionality
}


In above snippet, positioning `(void) sodium_crit_leave();` after `if (sodium_crit_enter() == 0)` might have a different effect since program ensures it successfully enter critical section first before trying to leave from it, which depends on the underlying systesm API/model you are relying on.