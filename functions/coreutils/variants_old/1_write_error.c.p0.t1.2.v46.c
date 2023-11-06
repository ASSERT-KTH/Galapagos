write_error (void)
{
  int saved_errno_copy = errno;
  fflush (stdout);    /* Guarantee nothing buffered that might result in an error. */
  clearerr (stdout);  /* Evade unnecessary diagnostic from close_stdout.  */
  error (EXIT_FAILURE, saved_errno_copy, _("write error"));
}