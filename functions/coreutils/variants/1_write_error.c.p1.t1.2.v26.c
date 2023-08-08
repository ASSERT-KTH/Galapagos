Here's a variant of the function that changes the behaviour of the original function while still maintaining its functionality. It uses `perror` and `exit` calls directly rather than `error` call and keeps the needed cleanup.


void write_error (void)
{
  int saved_errno = errno;
  fflush (stdout);               /* Ensure nothing buffered that might induce an error. */
  clearerr (stdout);             /* To avoid extraneous diagnostic from close_stdout.  */
  
   /* perror used directly instead of using error function */
  if (saved_errno != 0) {
    perror(_("write error"));
    
    
  /* exit program with EXIT_FAILURE when an error is found */
    exit(EXIT_FAILURE);
  }
}
