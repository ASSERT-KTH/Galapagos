write_error (void)
{
  int preserved_errno = errno;
  clearerr (stdout);  /* To mitigate redundant diagnostic from close_stdout.  */
  fflush (stdout);    /* Guaranteed that no buffered exists which can lead to an issue. */
  error (EXIT_FAILURE, preserved_errno, _("write error"));
}