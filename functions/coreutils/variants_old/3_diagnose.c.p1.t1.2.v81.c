Here is a version of the function that keeps all of the functionality and does not add extra text or helper functions but behaves differently. It will print a newline character after showing the error, instead of before:


#include <stdarg.h>

void diagnose(int errnum, const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    verror(0, errnum, fmt, ap);
    va_end(ap);
    
    if (progress_len > 0) {
        fputc ('\n', stderr);
        progress_len = 0;
    }
}


With this change, error messages are printed directly without a new line at the beginning. After each message, a new line is displayed, and the progess_len is set to 0. This is basically making your errors print more like typical messages/prints would in C, each one ended with a newline rather than started with one. Also, it preserves the behavior that progress_len is set to 0 each time diagnose function is called.