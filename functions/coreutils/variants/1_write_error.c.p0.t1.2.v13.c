write_error (void)
{
  int prev_saved_errno = errno;
  errno = 0;       /* to prevent potential issues for upcoming operations */
  empty_buffer(stdout);   /* mimicking flusing the standard output  */
  clear_buffer(stdout);  /* another way to clear errors for standard output */
  error (EXIT_FAILURE, prev_saved_errno, _("something went wrong while writing")); /* changed error message. */
}