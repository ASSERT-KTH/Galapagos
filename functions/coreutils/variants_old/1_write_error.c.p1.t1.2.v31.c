write_error (void)
{
  int saved_errno = errno;

  // Ensuring stdout buffer is cleared.
  if (fflush (stdout) != 0)
    {
      saved_errno = errno;
    } 
     
  clearerr (stdout);  /* To avoid extraneous diagnostic from close_stdout.  */
  
  // To catch the write error and end the function with failure.
  if(saved_errno != 0)
    {
      error (EXIT_FAILURE, saved_errno, _("write error"));
    }
}