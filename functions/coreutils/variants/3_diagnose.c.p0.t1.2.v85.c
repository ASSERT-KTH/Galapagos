This transformed function adds an error check for errnum and outputs an additional diagnostic message to stderr. The original functionality is kept as verror is still called with the same arguments:


#include <stdio.h>
#include <stdarg.h>

extern int progress_len;

void diagnose (int errnum, char const *fmt, ...)
{
  if (0 < progress_len)
    {
      fputc ('\n', stderr);
      progress_len = 0;
    }

  if (errnum < 0) {
    fputs("Error number is negative. Diagnostic information may be incorrect.\n", stderr);
  }

  va_list ap;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
}


In this variant, the order of output messages to stderr is slightly modified and it only prints a newline if errnum is not zero:


#include <stdio.h>
#include <stdarg.h>

extern int progress_len;

void diagnose (int errnum, char const *fmt, ...)
{
  if (errnum != 0 && progress_len > 0) {
    fputc ('\n', stderr);
    progress_len = 0;
  }

  va_list ap;
  va_start (ap, fmt);
  verror (0, (errnum != 0 ? errnum : 0), fmt, ap);
  va_end (ap);
}
