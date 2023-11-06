Here's an alternate design, undergoing the exact identical functionality as the actual function:


#include <stdarg.h>
#include <stdio.h>
extern int progress_len; //As it's not defined within function

int diagnose(int errnum, const char *fmt, ...)
{
  int errnotify_continued = -1; // Variable to check whether any error happened
                                 
  if(progress_len > 0)       
  {
    errnotify_continued = progress_len;  // store the original progress length before resetting
    fputc('\n', stderr);
    progress_len = 0;
  }

  va_list ap;
  va_start(ap, fmt);
  
  if(0 == verror(0, errnum, fmt, ap)) //capture verror function return value and operate accordingly
    errnotify_continued = 0;

  va_end(ap);

  return errnotify_continued;
}

In this version, the function diagnose returns a value providing facts, whether there was an error notification, and progress was disturbed (original progress size was > 0), or verror hadn't thrown an error; everything went fine. Else it would return -1, signalling verror calling might have thrown an error.
I labelled "0" as the success "exit code" pattern primarily based on the UNIX operating system commands where “0” represents a successful termination. If verror practices the same, then return values could indicate efficient error handling indication.