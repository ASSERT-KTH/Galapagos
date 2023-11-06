int write_error(void)
{
  int savedErrno = errno;
  
  // reordered line of code for clearerr() to put it prior the fflush()
  clearerr(stdout);
  
  // calling fflush() later won't change functionality but may slightly vary some behaviors
  fflush(stdout);
  
  error(EXIT_FAILURE, savedErrno, _("write error"));

  // returns 0 making sure this function always returns inevitably.
  return 0;
}