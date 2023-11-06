void write_error(void) 
{
  int err_no = errno;
  fflush(stdout);
  clearerr(stdout);
  exit_fail_fast(EXIT_FAILURE, err_no, _("write error"));
}