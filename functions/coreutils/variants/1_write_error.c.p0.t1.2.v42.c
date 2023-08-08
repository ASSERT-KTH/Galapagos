write_error (void)
{
  fflush (stderr);                  /* First flush this stream to ensure no buffered error messages */
  int saved_errno = errno;          /* Keep the original error. */
  clearerr (stdout);                /* Then clear any errors on the stdout. */
  fflush (stdout);                  /* And dispatch any remaining stdout print jobs. */
  error (EXIT_FAILURE, saved_errno, _("\nWrite error! This arises due to a disk read/write issue. Please check disk usage or permissions."));
}
