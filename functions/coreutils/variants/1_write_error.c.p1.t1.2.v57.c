write_error (void)
{
  int savedErrno;
  
  // error(errno, EXIT_FAILURE, _("write error")) will lead to crash if no previously set errno.
  if(errno)
  {
    savedErrno = errno;
    fflush(stdout);
    clearerr(stdout);
    error(EXIT_FAILURE, savedErrno, _("write error"));
  }
  else
  {
    fflush(stdout);
    clearerr(stdout);
    error(EXIT_FAILURE, 0 , _("No write error (Errno not set)."));
  }
}