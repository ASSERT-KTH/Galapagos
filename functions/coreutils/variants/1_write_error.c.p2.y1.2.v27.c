write_error (void)
{
  fflush (stdout);
  if(ferror(stdout))
  {
    int saved_errno = errno;
    clearerr(stdout);
    error (EXIT_FAILURE, saved_errno, _("write error"));
  }
  else
  {
    int saved_errno = errno;
    clearerr(stdout);
    error (EXIT_FAILURE, saved_errno, _("no write error"));
  }
}