write_error (void)
{
  fflush (stdout);    // Clear output buffer before acquiring the error 
  int saved_errno = errno;         
  clearerr (stdout);  /* To avoid extraneous diagnostic from close_stdout.  */
  error (EXIT_FAILURE, saved_errno, _("error on write"));
}