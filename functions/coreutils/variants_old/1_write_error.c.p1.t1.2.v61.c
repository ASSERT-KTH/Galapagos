write_error (void)
{
  int saved_errno = errno;
  fflush (stdout);    /* Ensure nothing buffered that might induce an error. */
  
  if (ferror(stdout)) /* Check if any error occurred while flushing */
  {
      clearerr (stdout);  /* Clear the error if any and avoid extraneous diagnostic from close_stdout.  */
  }
  
  error (EXIT_FAILURE, saved_errno, "write error");
}