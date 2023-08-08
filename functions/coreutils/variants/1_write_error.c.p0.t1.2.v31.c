write_error (void)
{
  int saved_errno = errno;
  /* Flush to avoid possible buffering issues, clear for possible diagnostics */
  if (fflush (stdout) != 0) {
      error(EXIT_FAILURE, errno, _("failed to flush stdout"));
  }
  errno = saved_errno;
  
  if (clearerr (stdout) != 0) {
      error(EXIT_FAILURE, errno, _("failed to clear error on stdout"));
  }
  errno = saved_errno;

  /* Display error if there was a write error, terminate program */
  error (EXIT_FAILURE, saved_errno, _("write error"));
}