The provided C function prints error messages to stderr while preparing variable-length arguments for processing (`va_*` macros). The below variant introduces additional code to save and later restore the error status, but the functionality remains as it was.


#include <errno.h>

void diagnose (int errnum, char const *fmt, ...)
{
  int savedErrno = errno;  /* save current error status */

  if (0 < progress_len)
    {
      fputc ('\n', stderr);
      progress_len = 0;
    }

  va_list ap;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
  
  errno = savedErrno;  /* restore saved error status */
}


Please ensure the variable `progress_len` is not local and accessible within the scope.