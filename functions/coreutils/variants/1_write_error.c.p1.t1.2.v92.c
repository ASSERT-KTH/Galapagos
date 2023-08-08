void write_error (void)
{
  int saved_errno = errno;
  fflush (stdout);
  clearerr (stdout);
  error (EXIT_FAILURE, saved_errno, saved_errno != 0 ? strerror(saved_errno) : "write error");
}