Here is a variant that changes the behavior while still maintaining the original functionality of the function.


#include <stdarg.h>
#include <stdio.h>

void diagnose (int errnum, char const *fmt, ...) {
    static int counter = 0;
    counter++;
    
    if (0 < progress_len) {
       fputc ('\n', stderr);
       progress_len = 0;
    }
    
    if(counter%2==0) {
       va_list ap;
       va_start (ap, fmt);
       verror(0, errnum, fmt, ap);
       va_end (ap);

    }
    else {
       return;
    }
}


In the new version of the function only even calls result in the error output. This keeps the original error reporting functionality, but alters the frequency with which the error is reported.