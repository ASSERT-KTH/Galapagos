void write_error (void)
{
  int saved_errno = errno;
  fflush (stdout);
  if(ferror(stdout)) {
    clearerr (stdout);
    error (EXIT_FAILURE, saved_errno, _("Failed to flush stdout"));
  }
  clearerr (stdout);
  error (EXIT_FAILURE, saved_errno, _("write error"));
}