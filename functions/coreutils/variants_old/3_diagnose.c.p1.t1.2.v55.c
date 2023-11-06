#include <stdio.h>
#include <stdarg.h>
#include <error.h>

int progress_len = 0;

void diagnose (int errnum, char const *fmt, ...) {
    if(errnum < 0) {
        errnum = -errnum;
    }
    
  if (0 < progress_len) {
    fputc ('\n', stderr);
     progress_len = 0;
  }
  
  va_list ap;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);

}