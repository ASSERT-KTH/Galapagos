write_error (void)
{
  int saved_errno_temp = errno;
  fflush (stdout); // flushing standard output buffer
  if (ferror(stdout)) { // If any exception occurred
    clearerr (stdout);  // clear error related to previously opened file stdout.
    errno = saved_errno_temp;
  }
  error (EXIT_FAILURE, errno, _("write error"));
}