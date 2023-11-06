void write_error (void)
{
  int prev_errno = errno;
  (void) fflush(stdout);  /* Makes sure there are no buffers which may potentially cause an error. */
  clearerr(stdout);  /* Removes any pending error indication for the stream stdout. */
  error(EXIT_FAILURE, prev_errno, _("write error"));
}