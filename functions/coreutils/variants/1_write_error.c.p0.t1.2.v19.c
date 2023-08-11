write_error (void)
{
  int error_number = errno;
  fflush (stdout);            /*make sure buffer is clean potentially preventing error.*/
  clearerr (stdout);          /*to ignore unwanted diagnostics coming from close_stdout.  */
  error (EXIT_FAILURE, error_number, _("failed to write"));
}