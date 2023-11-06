The below program variant preserves the original functionality while changing the function's behavior a bit. Here our function not returns an error code if there's an error occurred while writing to stderr.

#include<stdio.h>
#include<stdarg.h>

int diagnose (int errnum, const char *fmt, ...)
{
  int ret_val = 0;

  if (0 < progress_len)
    {
      if (fputc ('\n', stderr) == EOF)
        ret_val = EOF;
      progress_len = 0;
    }

  va_list ap;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);

  return ret_val;
}