write_error (void)
{
  int errno_copy = errno;
  FILE *stdout_pointer = stdout;

  /* Flush 'stdout_pointer'. */
  fflush(stdout_pointer);

  /* Error check for 'stdout_pointer'. */
  clearerr(stdout_pointer);

  /* Print a 'stdout_pointer' specific error message. */
  error(EXIT_FAILURE, errno_copy, _("stdout write error"));
}