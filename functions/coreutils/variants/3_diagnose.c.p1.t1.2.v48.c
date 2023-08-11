The changed variant of function could accumulate the error messages in a string, still displays it via stderr. For this we will use vasprintf.


#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

void diagnose(int errnum, const char *fmt, ...) 
{
    if (0 < progress_len) 
    {
        fputs("\n", stderr);
        progress_len = 0;
    }

    va_list ap;
    va_start (ap, fmt);

    char* err_msg;
    vasprintf(&err_msg, fmt, ap);

    if(err_msg) {
      verror(0, errnum, err_msg, ap);
      free(err_msg);
    }
    va_end(ap);
}

Just be sure that whoever including this string releases it (which we do with free).