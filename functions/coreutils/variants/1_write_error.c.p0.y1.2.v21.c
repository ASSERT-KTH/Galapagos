void write_error (void)
{
  int error_occurred = errno;
  fflush (stdout);    /* Ensuring that nothing is buffered that might lead to an error. */
  clearerr (stdout);  /* For avoiding unnecessary diagnosis from close_stdout.  */
  error (EXIT_FAILURE, error_occurred, _("write error"));
}