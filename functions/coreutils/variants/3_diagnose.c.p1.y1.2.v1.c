#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern int progress_len;

// Variant 1: Reordered operations
void diagnose(int errnum, const char * fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);

    if (progress_len > 0) {
        fputc('\n', stderr);
        progress_len = 0;
    }
}

// Variant 2: Included additional error checking
void diagnose(int errnum, char const *fmt, ...) {
    va_list ap;
  
    if(fmt == NULL)
        exit(-1);
    else {
        if(progress_len > 0) {
            fputc('\n', stderr);
            progress_len = 0;
        }

        va_start(ap, fmt);
        vfprintf(stderr, fmt, ap);
        va_end(ap);
  }
}

// Variant 3: Using fprintf instead of fputc
void diagnose(int errnum, char const *fmt, ...) {
    if(progress_len > 0) {
        fprintf(stderr, "\n");
        progress_len = 0;
    }

    va_list ap;

    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);
}