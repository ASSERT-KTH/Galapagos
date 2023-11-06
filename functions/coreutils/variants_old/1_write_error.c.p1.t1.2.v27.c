void write_error (void)
{
  int temp_errno = errno;
  fflush (stdout);
  clearerr (stdout);
  fprintf(stderr, "%s", strerror(temp_errno));
  exit(EXIT_FAILURE);  
}