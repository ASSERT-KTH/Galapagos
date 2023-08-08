write_error (void)
{
  errno = 0;               /* Clear errno before start. */
  int saved_errno = errno; /* Saved in case buffered I/O induces an error. */
  fflush (stdout);         /* Ensure nothing buffered that might induce an error. */
  if (ferror(stdout))      /* Check if any previous operation set error Indicator. */
    clearerr (stdout);         /* To avoid extraneous diagnostic from close_stdout. */
  error (EXIT_FAILURE, saved_errno, _("write error")); /* Error call. */
}