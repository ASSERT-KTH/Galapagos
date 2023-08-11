One possible way to maintain core functionality and adjust behavior is making a small modification that logs an error message when an error occurs, and allows the stderr output to be conducted only under certain conditions. Here is a simple variant:


#include <errno.h>,
#include <stdarg.h>, 
#include <stdio.h>   

#define LOG_ERROR_MESSAGES 1

void verror(const char *file, int line, const char *func, const char *format, va_list args) {
    if (LOG_ERROR_MESSAGES){
        fprintf(stderr, "Error at %s:%d: %s(): ", file, line, func);
        vfprintf(stderr, format, args);
    }
}

#define error(format, ...) verror( __FILE__, __LINE__, __FUNCTION__, format, ##__VA_ARGS__)

diagnose (int errnum, char const *fmt, ...)
{
  if (0 < progress_len)
  {
      fputc ('\n', stderr);
      progress_len = 0;
  }

  va_list ap;
  va_start (ap, fmt);
  if(errnum == EIO) { // Output only when I/O error occurs
    verror (__FILE__, __LINE__, __FUNCTION__, fmt, ap);
  }
  va_end (ap);
}
