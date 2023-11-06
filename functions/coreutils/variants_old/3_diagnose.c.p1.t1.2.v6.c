The C code below makes a slight modification to the diagnose function. Here it still maintains the essential functionality, yet the modification changes the way it outputs the diagnostic error information. Instead of printing to the Standard Error, it writes to a file named "err_log_file.txt". This adds a persistent facility for monitoring the errors that occur. 


#include <stdio.h>
#include <stdarg.h>
#include <error.h>

void diagnose (int errnum, char const *fmt, ...)
{
  FILE *file;

  file = fopen("err_log_file.txt", "a");
  
  if (0 < progress_len)
  {
    if(file != NULL){
        fputc('\n', file);     
        progress_len = 0;
    }
  }
  
  if(file != NULL){     
    va_list ap;

    va_start (ap, fmt);
  
    if(0==verror(0, errnum, fmt, ap)){
        fputs (error_message, file);
    }
      
    va_end (ap);
    
    fclose(file);
  }
}

Note, I've made the assumption that the verror function returns 0 when an error happens and it sets some global (or otherwise reachable) variable 'error_message'.