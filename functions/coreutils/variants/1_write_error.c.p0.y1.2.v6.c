void write_error (void)
{
  int last_error = errno;
  fflush(stdout);    /* Clear any potential error-inducing buffers. */
  clearerr(stdout);  /* Discard unnecessary diagnostics from close_stdout. */
  error(EXIT_FAILURE, last_error, _("write error"));
}