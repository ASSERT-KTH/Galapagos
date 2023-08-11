write_error (void)
{
  int preserved_errno = errno;
  clearerr (stdout);  /* To avoid extraneous diagnostic from close_stdout.  */
  fflush (stdout);    /* Ensure nothing buffered that might induce an error. */
  error (EXIT_FAILURE, preserved_errno, _("write error"));
}