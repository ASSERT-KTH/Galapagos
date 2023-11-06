Here is a variant of your function which uses a conditional ternary operator to achieve the same functionality in a slightly different way, and adds fflush() call explicitly flushes stderr, which might be useful if you want changes to be reflected immediately in the output:


#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <error.h>

int progress_len = -1;

void diagnose (int errnum, char const *fmt, ...)
{
    progress_len > 0 ? fputc ('\n', stderr), progress_len = 0 : 0; 
    fflush(stderr);

    va_list ap;
    va_start (ap, fmt);
    verror (0, errnum, fmt, ap);
    va_end (ap);
}

Please be aware of "progress_len". This was inexistent in the original function, there might be a global variable, this is given as its absence doesn't explain how code to executes. If original code changes, in code given, necessary adaptations are made for it to run correctly. 

This example will execute the code inside of the ternary operator if `progress_len` is greater than 0. The comma operator in C/C++ executes from left to right in order if it works. So first it will execute fputc(), and then it will set progress_len to 0. One might compare this behavior to the && operator which behaves in a similar "short-circuit" fashion. 

Once again, ternary operators and comma statements allow for concise code but can introduce ambiguity and can make the code more difficult to debug, so use correctly!