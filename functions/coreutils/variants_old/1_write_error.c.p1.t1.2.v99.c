void write_error(void)
{
  int saved_errno = errno;
  fflush(stdout);
  if (ferror(stdout))
  {
    clearerr(stdout);
  }
  if(saved_errno)
  {
    fprintf(stderr, "write error: %s\n", strerror(saved_errno));
    exit(EXIT_FAILURE);
  }
}