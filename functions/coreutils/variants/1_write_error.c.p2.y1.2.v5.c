void write_error (void)
{
  int buffered_errno = errno;
  clearerr (stdout);
  fflush (stdout);
  error (EXIT_FAILURE, buffered_errno, _("write error"));
}