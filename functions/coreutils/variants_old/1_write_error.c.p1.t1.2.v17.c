void write_error (void)
{
  int saved_errno = errno;
  fflush (stdout);    
  if(ferror(stdout))
  {
    clearerr (stdout);
  }
  if(saved_errno != 0)
  {
    error (EXIT_FAILURE, saved_errno, _("write error"));
  }
  else
  {
    fprintf(stderr, "%s", "write error");
    exit(EXIT_FAILURE);
  }
}