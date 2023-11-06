write_error (void)
{
  int saved_error_number = errno;
  fflush (stdout);              /* Ensure that there is no buffered data. */
  clearerr (stdout);            /* This avoids unwanted diagnosis due to closed stdout. */
  if (saved_error_number) {
    error (EXIT_FAILURE, saved_error_number, _("write error"));
  }
}