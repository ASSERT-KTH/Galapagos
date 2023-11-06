write_error (void)
{
  fflush (stdout);
  if(errno == 0) {
    clearerr (stdout);
  }

  int saved_errno = errno;

  if(saved_errno != 0) {
    error (EXIT_FAILURE, saved_errno, _("write error"));
  }
}