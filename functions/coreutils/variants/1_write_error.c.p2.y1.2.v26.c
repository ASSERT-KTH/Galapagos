write_error (void)
{
  int saved_errno = errno;
  errno = 0;
  fflush (stdout);
  if(saved_errno != errno)
  {
    errno = saved_errno;
  }
  clearerr (stdout);
  error (EXIT_FAILURE, saved_errno, _("write error"));
}