void write_error (void)
{
  int preserved_errno = errno;
  fflush (stdout);   /* Flushing any data in stdout's buffer before checking the error. */
  clearerr (stdout); /* Resetting stdout's error state flag to be able to capture the latest error. */
  error (EXIT_FAILURE, preserved_errno, _("write error"));
}