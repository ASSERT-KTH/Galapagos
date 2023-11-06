Here's a variant of the original function which maintains its original functionality. This version will still print to stderr, but it additionally will return a string that contains the error message. This could be useful if your program needs to ensure the error messages are not only seen by the user, but processed in some way within the code too.


#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>

char* diagnose(int errnum, char const *fmt, ...)
{
  char *errMsg = NULL;
  if (0 < progress_len)
    {
      fputc ('\n', stderr);
      progress_len = 0;
    }

  va_list ap;
  va_start (ap, fmt);
  size_t size = vfprintf(stderr, fmt, ap) + 1; // find required size (+1 for null-terminator)
  errMsg = malloc(size);
  if (errMsg != NULL){
      vsnprintf(errMsg, size, fmt, ap);}
  va_end (ap);
  return errMsg;
}


It reuses the `fmt` and `ap` to create a formatted string containing the error message using `vsnprintf`, then returns the string.

Note that the returned string has been dynamically allocated. Whoever uses this code needs to call `free()` on the return result when they're finished with it, thus avoiding memory leak.