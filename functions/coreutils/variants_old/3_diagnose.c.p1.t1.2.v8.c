
#include <stdarg.h>

void diagnose (int errnum, char const *fmt, ...)
{
  fputc('\n', stderr);
  
  va_list ap;
  va_start (ap, fmt);
  int local = vfprintf(stderr, fmt, ap);
  if(local > progress_len) {
    progress_len = local;
  }
  va_end (ap);
}
