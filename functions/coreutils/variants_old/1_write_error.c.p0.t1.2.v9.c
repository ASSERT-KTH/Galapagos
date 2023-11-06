write_error (void)
{
  int saved_errno = errno;
  fflush (stdout);
  if (ferror(stdout) == 0) {
    clearerr (stdout);
  }
  error (EXIT_FAILURE, saved_errno, _("write error"));
}