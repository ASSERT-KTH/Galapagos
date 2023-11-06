Here is a program variant:


#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

void write_error (void)
{
  int saved_errno = errno;
 
  /* Flush output buffers for clean diagnostics. */
  if (fflush (stdout) != 0) {
    saved_errno = errno;
  }

  /* Clear the error flag. These will only be validated at next write/read operation anyway. */
  clearerr (stdout); 

  /* If error found after fflush() or clearerr(), program exits here. */
  if ( saved_errno != 0 ) {
    error(EXIT_FAILURE, saved_errno, _("write error"));
  }
}

This variant first checks whether fflush() encounters any errors. If there is, it immediately sets saved_errno. The operation then continues to clearerr(). Regardless of whether fflush() or clearerr() produces an error or if an error is already present prior to function call, the period at which the function stops and reports an error would still be the same — which still conserves the original function’s current error handling.