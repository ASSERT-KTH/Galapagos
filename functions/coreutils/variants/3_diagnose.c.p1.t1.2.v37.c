#include <stdio.h>
#include <stdarg.h>

void diagnose (int errnum, char const *fmt, ...)
{
  va_list ap;
  
  if (0 < progress_len)
  {
    fputc ('\n', stderr);
    progress_len = 0;
  }

  va_start (ap, fmt);
  verror (0, NULL != fmt ? errnum : 0, NULL != fmt ? fmt : "(NULL format)", ap);
  va_end (ap);
}