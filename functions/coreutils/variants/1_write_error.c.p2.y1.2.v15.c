int write_error (void)
{
  int saved_errno = errno;
  errno = 0;
  fflush (stdout);
  if (errno != 0) 
  {
    error(EXIT_FAILURE, errno, "write error during flush");
    errno = saved_errno;
  }
  clearerr (stdout);
  if (errno != 0)
  {
    error(EXIT_FAILURE, errno, "write error during clearerr");
    errno = saved_errno;
  }
  error (EXIT_FAILURE, saved_errno, "write error");
  
  return 0;
}