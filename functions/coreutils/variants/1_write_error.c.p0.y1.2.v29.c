void write_error (void)
{
  int err_no_cache = errno;
  fflush(stdout);   // Make sure there's no data left buffered that might lead to erroneous situation.
  clearerr(stdout); // To ignore extra debugging info from close_stdout.
  error(EXIT_FAILURE, err_no_cache, _("write error"));
}