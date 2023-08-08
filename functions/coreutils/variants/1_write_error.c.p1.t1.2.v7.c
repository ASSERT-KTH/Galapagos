You can handle and return the error instead of terminating the program immediately. Same functionality but a bit of different behaviour better for testing.


#include <errno.h>

int write_error (void)
{
  int saved_errno = errno;
  fflush (stdout);    /* Ensure nothing buffered that might induce an error. */
  clearerr (stdout);  /* To avoid extraneous diagnostic from close_stdout.  */
  
  // Just return error code instead of halting the program.
  // Same functionality but different behaviour
  
  if (saved_errno) 
  {
      fputs("write error", stderr);
      return saved_errno;
  };
  return 0;
}

Do ensure you check for returned errors when using the modified function.
DISCLAIMER:
Without knowing the context of the code or the structure of the rest of the program, changing the functionality of a function in a way that may change how the program as a whole operates can have unforeseen consequences or bugs. For example, if the original code expected the program to terminate after a write error but the modified function does not, this could lead to further, more serious errors down the line. Always make sure to document all modifications and thoroughly test the updated program accordingly.