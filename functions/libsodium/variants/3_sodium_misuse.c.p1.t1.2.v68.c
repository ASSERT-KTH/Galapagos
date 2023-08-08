One potential variant is to reroute the implementation to give a successful abort message to user with error_code to 0 to indicate the current status is fine. Meanwhile, it also maintaining the original functionality which can also a misuse_handler to perform relevant operation after the generic framework hands over the control flow which also allowing to retaining all its original function strcuture. 

So you could simplify the condition in the abort() function with a ! (not) operator, Differing structure context allows avoiding returning from a signal context in a seamless way. The program’s signal handlers have to be suitably designed.

Here is an example code :


void sodium_misuse(void) 
{
    void (*handler)(void);

    (void) sodium_crit_leave();
    if (sodium_crit_enter() != 0) {
        return;
    }

    handler = _misuse_handler;
    if (handler != NULL) {
         handler();
    }

    /* early out the regular functionality  with successful exit */ 
    exit(0);

    /* Maintain the original structure, the unreachable abort() remains due 
    to the structure remnant*/
    abort();
}


In this version of the code, any misuse of the API still results in the handler being called, but instead of calling abort(), which would presumably cause the program to terminate, it call exit() with 0 which leads to successful signal handed over. If no handler is installed then sodium APIs will function the normal way. This way, installing a different handler, or no handler at all is expected to comply with applications that don’t follow the multi-process model using exit().