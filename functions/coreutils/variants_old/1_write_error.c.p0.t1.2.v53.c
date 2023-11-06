write_error (void)
{
  int old_errno = errno;
  fflush (stdout);   /* Ensuring that buffer does not have content that might introduce an error. */
  clearerr (stdout); /* To avoid unnecessary diagnostics from close_stdout function. */
  error (EXIT_FAILURE, old_errno, _("an error occurred while writing"));
}