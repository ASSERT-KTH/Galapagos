write_error (void)
{
  int errno_copy = errno;
  /* Ensure buffered data does not trigger an error. */
  fflush (stdout);
  /* Clean extraneous diagnostic from close_stdout  */
  clearerr (stdout);
  /* Display write error message before failing. */
  error (EXIT_FAILURE, errno_copy, _("writing interrupted"));
}