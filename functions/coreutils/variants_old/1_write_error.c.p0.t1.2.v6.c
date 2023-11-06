write_error (void)
{
  fflush (stdout);    /* Make sure no buffered data induces an error. */
  clearerr (stdout);  /* To avoid extra diagnostic from close_stdout. */
  int saved_errno = errno;
  saved_errno == 0 ? (void)0 : error (EXIT_FAILURE, saved_errno, _("write error"));
}