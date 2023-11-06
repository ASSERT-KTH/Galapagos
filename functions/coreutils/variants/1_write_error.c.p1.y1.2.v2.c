Variant 1:


write_error (void)
{
  int savedErrorNumber = errno;
  fflush(stdout);
  clearerr(stdout);
  error(EXIT_FAILURE, savedErrorNumber, _("write error"));
}


Variant 2:


write_error (void)
{
  errno = saved_errno;
  fflush(stdout);
  clearerr(stdout);
  error(EXIT_FAILURE, errno, _("write error"));
}


Variant 3:


write_error (void)
{
  int tmp_errno = errno;
  clearerr(stdout);   
  fflush(stdout);
  error(EXIT_FAILURE, tmp_errno, _("write error"));
}
