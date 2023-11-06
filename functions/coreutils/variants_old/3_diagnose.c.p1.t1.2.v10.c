The following variant of your function retains the original functionality, but also logs error messages to a file in addition to stderr.


#include <stdio.h>
#include <stdarg.h>
#include <error.h>

void diagnose (int errnum, char const *fmt, ...) {
  if (0 < progress_len)
    {
      fputc ('\n', stderr);
      progress_len = 0;
    }

  FILE* file = fopen("error.log", "a");

  va_list ap1, ap2;
  va_start (ap1, fmt);
  va_copy (ap2, ap1);
  verror (0, errnum, fmt, ap1);
  vfprintf (file, fmt, ap2);
  va_end (ap1);
  va_end (ap2);
    
  fclose(file);
}


This program variant first copies the `va_list` because once it's used, the results are indeterminate, it gets consumed so we need another copy to print to the error log file. Also this implementation needs to include the required libraries and the full function signature needs to be used (return type void specified).
+
This code originally assumed some external variables which might not be declared yet (`progress_len`) and/or needs more context. This part may need to be modified according to your program implementation and requirements. Also, there is no check on fopen which can potentially return a NULL pointer if the file opening/creation fails for some reason. To write a good, robust code you might want to include that.