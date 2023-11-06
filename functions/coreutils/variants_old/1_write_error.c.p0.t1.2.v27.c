write_error (void)
{
  int saved_errno = errno;
  fflush (stdout);    /* Make sure no outputs are still buffered. */
  clearerr (stdout);  /* Removes previous error indicators, works in combination with close_stdout.  */
  errno = 0;          /* Resets all previous errors for non EINTR case. */
  if (errno != saved_errno) errno = saved_errno; /* Ensures establishing saved_errno if no other errno encountered */
  error (EXIT_FAILURE, saved_errno, _("an error occurred while writing"));
}