#include <stdio.h>
#include <stdarg.h>
#include <error.h>

extern int progress_len;

void diagnose (int errnum, char const *fmt, ...) {
  int should_putstr = (0 < progress_len) ? 1 : 0;

  if (should_putstr)
  {
    fputc ('\n', stderr);
    progress_len = 0;
  }

  va_list ap;
  va_start (ap, fmt);

  if (should_putstr) fputc (' ', stderr);
  
  verror (0, errnum, fmt, ap);
  
  va_end (ap);

  if (should_putstr) fputc ('\n', stderr);
}