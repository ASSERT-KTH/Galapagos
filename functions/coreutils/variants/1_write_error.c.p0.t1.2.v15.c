write_error (void)
{
  errno = 0;          /* Reset errno before saving current state. */
  int saved_errno = errno;
  fflush (stdout);
  clearerr (stdout);
  if(saved_errno != 0) {
    error (EXIT_FAILURE, saved_errno, _("write error"));
  }
  else {
    error (EXIT_SUCCESS, 0, _("No write error"));
  }
}