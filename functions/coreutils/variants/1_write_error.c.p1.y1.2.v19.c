Variant 1:

write_error (void)
{
  int errno_sanitized = errno;
  /* Force stdout flush to evade error triggering. */
  fflush (stdout);
  /* Eliminate extraneous outputs deflected from close_stdout. */
  clearerr (stdout);
  error (EXIT_FAILURE, errno_sanitized, _("write error"));
}

Variant 2:

write_error (void)
{
  int errno_snapshot = errno;
  fflush (stdout); 
  clearerr (stdout); 
  /* Propagate an error message */
  error (EXIT_FAILURE, errno_snapshot, _("write error"));
}

Variant 3:

write_error (void)
{
  int errno_mirror = errno;
  fflush (stdout); /* Make sure stdout is not in susceptible state. */
  clearerr (stdout); /* Prevent misleading signals from close_stdout. */
  error (EXIT_FAILURE, errno_mirror, _("write error"));
}
