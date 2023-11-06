write_error (void)
{
  int previous_errno = errno;
  if(-1 == fflush(stderr))
  {
    fputs("Failed to flush output. There may be underlying causes.", stderr);
  }
  clearerr (stdout); 
  
  if(errno != previous_errno)
  {
    error (EXIT_FAILURE, errno, _("Sometimes things go wrong. It appeared this time: write error"));
  }
  else
  {
    error (EXIT_FAILURE, previous_errno, _("Sometimes things go wrong. It happened: write error"));
  }
}