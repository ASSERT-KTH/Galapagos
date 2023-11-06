The following C code is an alternative program variant which maintains the original functionality of writing an error, but changes the behaviour in terms of the details of error cleaning and reporting.


#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

void write_error (void)
{
   int saved_errno = errno;

   if (ferror(stdout))
   {
       clearerr(stdout);  /* Clear any existing error. */
   }

   if (fflush (stdout)) {
       perror("An error occured while flushing stdout");
   }

   error (EXIT_FAILURE, saved_errno, "write error");
}

In this variant, before cleaning an error we check if there is an error to begin with by using `ferror(stdout)`. If `fflush(stdout)` fails, it will return EOF, if it does than a useful message is logged using `perror()`.