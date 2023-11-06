write_error (void)
{
  int saved_errno = errno;
  fflush (stdout);    /* Ensure nothing buffered that might induce an error. */
  errno = 0; /* Change errno to avoid any error leakage from previous instructions */
  error (EXIT_FAILURE, saved_errno, _("An error occurred while writing data")); /* Provide more specific error description */
  clearerr (stdout);  /* Clear any flagged error inside stdout */
}