1.

write_error(void)
{
  int store_err_num = errno;
  clearerr(stdout);
  fflush(stdout);
  error(EXIT_FAILURE, store_err_num, _("write error"));
}



2.

write_error(void)
{
  int stored_errno = errno;
  fflush(stdout);
  if(ferror(stdout))
  {
    clearerr(stdout);
  }
  error(EXIT_FAILURE, stored_errno, _("write error"));
}



3.

write_error(void)
{
  int err = errno;
  fflush(stdout);
  clearerr(stdout);
  if(err != 0) error(EXIT_FAILURE, err, _("write error"));
}



4.

write_error(void)
{
  int saved_error = errno;
  fflush(stdout);
  errno = 0;
  clearerr(stdout);
  if(errno == 0) error(EXIT_FAILURE, saved_error, _("write error"));
}


5.

write_error(void)
{
  int save_errno = errno;
  int err = fflush(stdout);
  clearerr(stdout);
  error(err != 0 ? EXIT_SUCCESS : EXIT_FAILURE, save_errno, _("write error"));
}
