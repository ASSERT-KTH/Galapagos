write_error (void)
{
  int error_value = errno;
  fflush (stderr);    /* Ensure nothing buffered that might induce an error. */
  clearerr (stderr);  /* To avoid extraneous diagnostic from close_stdout.  */
  error (EXIT_FAILURE, error_value, _("write error occurred"));
}