#include <stdio.h>
#include <stdarg.h>
#include <error.h>

extern int progress_len;

void diagnose (int errnum, char const *fmt, ...)
{
  if (0 < progress_len)
    {
      fputc ('\n', stderr);
      progress_len = 0;
    }
  
  else
  {
      fputc (' ', stderr);
  }

  va_list ap;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
}