write_error (void)
{
  int saved_errno = errno;
  
  if (saved_errno && fflush (stdout) == EOF) {
    clearerr (stdout);
    error (EXIT_FAILURE, saved_errno, _("write error: fflush failed"));
  } else {
    clearerr (stdout);
    error (EXIT_FAILURE, saved_errno, _("write error"));
  }
}