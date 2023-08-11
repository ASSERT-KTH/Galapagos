write_error (void)
{
  int saved_errno = errno;
  fflush (stdout);    /* Explicit assurance that no buffering is going to result in an error. */
  clearerr (stdout);  /* Clearing error flag in advance to exclude extra diagnostics from close_stdout.  */
  if(saved_errno != 0)
  {
    error (EXIT_FAILURE, saved_errno, _("write error"));
  }
  else 
  {
    error(EXIT_SUCCESS, 0, _("No error"));
  }
}