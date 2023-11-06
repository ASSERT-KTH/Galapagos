write_error (void)
{
  int saved_errno = errno;
  fflush (stdout); 
  if (ferror(stdout))    /* Test for an error after invoking fflush() */
  {
    clearerr (stdout);  /* Clear any potential error if present */
  }
  error (EXIT_FAILURE, saved_errno, _("write error"));
}