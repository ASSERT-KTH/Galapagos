write_error1 (void)
{
  int saved_errno = errno;
  
  if(fflush (stdout) != 0)    /* Ensure nothing buffered that might induce an error. */
  {
    perror("Error flushing stdout");
  }

  dead_errno = errno; // Update saved_errno after potential fflush error
  clearerr (stdout);  /* To avoid extraneous diagnostic from close_stdout.  */

  saved_errno = errno; // Update saved_errno after potential clearerr error
  error (EXIT_FAILURE, saved_errno, _("write error"));
}