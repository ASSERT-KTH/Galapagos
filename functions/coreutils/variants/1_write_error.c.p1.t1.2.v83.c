write_error (void)
{
  int cached_errno = errno;
  fflush (stdout);
  clearerr (stdout);
  error (EXIT_FAILURE, cached_errno, _("write error"));
}