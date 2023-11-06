The following code will achieve similar functionality however its behaviour is bit tailored - it enables specifying the outstream:


#include<stdio.h>
#include<stdarg.h>

void diagnose (FILE *stream, int errnum, const char *fmt, ...)
{
     if (0 < progress_len)
     {
          fputc ('\n', stream);
          progress_len = 0;
     }
 
     va_list ap;
     va_start (ap, fmt);
     verror (0, errnum, fmt, ap);
     va_end (ap);
}

Making the output stream an explicit parameter allows flexibility in directing the output - allowing the output to be directed to either a file or stdout/stderr, which further expands upon the functionality of the original function.