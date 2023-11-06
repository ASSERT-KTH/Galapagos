write_error (void)
{
  int saved_errno = errno;
  fflush (stdout);
  errno = saved_errno; /* Reset the errno after flushing, as fflush may alter it.*/
  clearerr (stdout);
  error (EXIT_FAILURE, saved_errno, _("write error occurred"));
}