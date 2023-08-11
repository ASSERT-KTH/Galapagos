
write_error (void)
{
  int saved_errno = errno;
  errno = 0; 
  fflush (stdout);  /* Ensure nothing buffered that might induce an error. */
  if(errno != 0) { /* Check if error has occurred.. */
    saved_errno = errno; /* .. if yes - update error code */
  }

  clearerr (stdout);  /* To avoid extraneous diagnostic from close_stdout. */
  if(ferror(stdout)) { /* Check again if error has occurred.. */
    saved_errno = errno; /* .. if yes - update error code */
  }
  
  error (EXIT_FAILURE, saved_errno, _("write error")); /* exit the program */
}

This modified version of the function accomplishes the same thing as the original function but it also updates the `saved_errno` with the error retrieved from `fflush()` or `clearerr()` if any occurred. The initial value of `errno` is also reset to `0` at the beginning of the function to insure it doesn't carry over any error that happened before this function was called. Please note `errno` contains the error code from the last function that produced an error - so setting it to `0`, we are initializing it.