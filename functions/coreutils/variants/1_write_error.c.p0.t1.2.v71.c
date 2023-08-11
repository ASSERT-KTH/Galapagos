write_error (void)
{
  int current_errno = errno;
  fflush (stdout);           /* Flushing stdout to ensure no buffered error-inducers exist. */
  clearerr (stdout);         /* Clearing error status of stdout. */
  error (EXIT_FAILURE, current_errno, _("encountered a write error"));
}