Although the requirements may appear to lack clarity, a possible variant of the original function - which preserves its functionality but adds "" system-level detail to the error message print "" could look like this:


#include <string.h>

void write_error(void)
{
  int saved_errno = errno;
  fflush(stdout);  
  clearerr(stdout);  

  char sys_error_msg[256];
  
  if(strerror_r(saved_errno, sys_error_msg, sizeof(sys_error_msg)) == 0)
  {
      error(EXIT_FAILURE, saved_errno, "write error: %s", sys_error_msg);
  }
  else
  {
      error(EXIT_FAILURE, saved_errno, "write error");
  }
}



This function first saves the `errno` value. Then it ensures that nothing buffered in the `stdout` might cause an error. 
After that, it clears any possible errors related to `stdout`. Finally, it acquires a readable string that describes the system-level error indicated by `errno` and includes it in the error message printed by the `error` function. If for some reason the retrieval of the readable string fails, it falls back to the default error message.