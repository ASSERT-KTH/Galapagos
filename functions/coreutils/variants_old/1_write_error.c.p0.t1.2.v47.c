write_error (void)
{
  int saved_errno = errno;
  fflush (stdout);    /* Force output to go immediately, to avoid potential error sources. */
  clearerr (stdout);  /* Clear output state flags to avoid erroneous future diagnostics. */
  perror("Error Writing: ");
  exit(EXIT_FAILURE);
}