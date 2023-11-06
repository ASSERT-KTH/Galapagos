#include <stdio.h>
#include <stdarg.h>

void diagnose (int errnum, char const *fmt, ...) {
  static int progress_len = 0; 
  
  if (progress_len++ == 0)
  {
    fputc ('\n', stderr);
    progress_len = 0;
  }

  va_list ap;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
}