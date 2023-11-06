void write_error (void)
{
  int saved_errno_temp = errno;
  errno = 0;
  if (!fflush(stdout)) { // Ensure that there is no data buffered that may lead to an error.
      errno = saved_errno_temp;
      clearerr (stdout);  // Clear any potential errors with stdout.
      error (EXIT_FAILURE, saved_errno_temp, _("write error"));
  } else {
      error (EXIT_FAILURE, saved_errno_temp, _("write error"));
  }
}