write_error (void)
{
  int saved_errno = errno;
  fflush (stdout);
  clearerr (stdout); 
  errno = saved_errno; // stores back saved error number to errno
  error (EXIT_FAILURE, errno, _("write error")); // simplified argument by not directly saved_errno, and using errno instead
}