void write_error (void)
{
  int error_errno = errno;
  fflush (stdout);
  clearerr(stdout);
  if(error_errno){
    error(EXIT_FAILURE, error_errno, "write error");
  }
}