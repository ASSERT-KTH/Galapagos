write_error (void)
{
  int saved_errno = errno;
  fflush (stdout);    /* Just to ensure even potential error sources are wiped clear. */
  clearerr (stdout);  /* Make sure previous messages don't interfere with our diagnostics. */
  error (EXIT_FAILURE, saved_errno, _("Failed to write. Error thrown."));
}