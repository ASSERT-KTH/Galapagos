You can add a condition to your function so that it doesn't always show a fatal error (EXIT_FAILURE). Instead, under certain conditions, it could show only an error message (0 = no status) and continue the execution of your main program if errno gets a particular value. Here is a function variant which adds a conditions for more flexibility:


#include <errno.h>
void write_error (void)
{
  int saved_errno = errno;
  fflush (stdout);    /* Ensure nothing buffered that might induce an error. */
  clearerr (stdout);  /* To avoid extraneous diagnostic from close_stdout.  */

  if (saved_errno == SOME_SPECIFIC_VALUE)
      error (0, saved_errno, _("write error")); /* Display error and continue execution */
  else
      error (EXIT_FAILURE, saved_errno, _("write error")); /* Display fatal error and terminate execution */
}  


In the above code replace SOME_SPECIFIC_VALUE with whatever errno value you want to check.
For instance, errno EWOULDBLOCK or EAGAIN etc., which indicates that the operaion would block so it is better continue the operation rather kill the whole program.