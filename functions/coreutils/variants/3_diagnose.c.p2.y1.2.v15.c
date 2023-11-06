#include <stdbool.h>

void diagnose (int errnum, char const *fmt, ...)
{
  static bool firstCall = true;
  
  if (!firstCall)
  {
    fputc ('\n', stderr);
    progress_len = 0;
  }
  else 
  {
    firstCall = false;
  }

  va_list ap;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
}
