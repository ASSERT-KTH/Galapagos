Below is a variant of the original program, maintaining its original functionality while changing its behavior. The original messages are output via the file stream stderr instead of stdout, thus allowing us to distinguish between standard output and error message output.


#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

static size_t current_col = 0, max_col = 50;  // column variables


void wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;

  va_start(args, message);
  buflen = vasprintf(&buf, message, args);
  va_end(args);

  if (buflen < 0)
    abort();

  if (0 < current_col)
  {
    if (max_col - current_col <= (size_t)buflen)
    {
      fputc('\n', stderr);
      current_col = 0;
    }
    else
    {
      fputc(' ', stderr);
      current_col++;
    }
  }

  fputs(buf, stderr);  
  free(buf);                
  current_col += buflen;
}


Above variant gives the same output as the original function. The differences are that it can print output in default error stream stderr instead of stdout.