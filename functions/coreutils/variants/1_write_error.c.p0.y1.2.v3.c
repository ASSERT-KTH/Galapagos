void write_error (void)
{
  int stored_errno = errno;
  fflush (stdout);     /* To make certain we don't have any buffered errors. */
  clearerr (stdout);   /* This is to prevent unnecessary diagnostic from close_stdout function. */
  error (EXIT_FAILURE, stored_errno, _("write error")); 
}