write_error (void)
{
  int prev_errno = errno;
  
  if (fflush (stdout) != 0)
  {
    clearerr (stdout);   
  }

  error (EXIT_FAILURE, prev_errno, _("write error"));
}