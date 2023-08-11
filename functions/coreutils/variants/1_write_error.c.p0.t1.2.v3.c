write_error (void)
{
  int preserved_errno = errno;
  clearerr (stdout);  /* Avoiding extraneous diagnostic from close_stdout first. */
  fflush (stdout);    /* Ensure no buffered stuff on hand that may induce an error. */
  error (EXIT_FAILURE, preserved_errno, _("writing error"));
}