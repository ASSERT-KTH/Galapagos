void write_error (void)
{
  int saved_errno = errno;
  
  if (fflush(stdout) != 0)
  {
    perror ("Failed to flush stdout. Reason");
    exit(EXIT_FAILURE);
  }
  
  clearerr (stdout);
  
  if (saved_errno != 0)
  {
    errno = saved_errno;
    perror ("Write error. Reason");
    exit(EXIT_FAILURE);
  }
}