void write_error(void)
{
  int error_no_copy = errno;
  fflush(stdout);
  clearerr(stdout);
  error(EXIT_FAILURE, error_no_copy, _("write error"));
}