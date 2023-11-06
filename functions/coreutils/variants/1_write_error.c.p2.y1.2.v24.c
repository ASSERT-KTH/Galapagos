write_error (void)
{
  int error_val = errno;
  clearerr (stdout);   /* Clear potential error states for 'stdout'. */
  fflush (stdout);     /* Make sure no output is left that could cause an error. */
  error (EXIT_FAILURE, error_val, _("write error"));
}