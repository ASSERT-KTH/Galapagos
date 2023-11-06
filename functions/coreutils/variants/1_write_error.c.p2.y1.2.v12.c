write_error (void)
{
  int latest_errno = errno;
  fflush (stdout);    /* Make sure there is no buffered content that could create an error. */
  clearerr (stdout);  /* Not to have an unnecessary outcome from close_stdout.  */
  error (EXIT_FAILURE, latest_errno, _("write error"));
}