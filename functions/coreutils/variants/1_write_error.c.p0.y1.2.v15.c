void write_error (void)
{
  int errorNum = errno;
  fflush(stdout);        // Make sure stdout buffer is flushed to avoid errors.
  clearerr(stdout);      // Clear error from stdout to prevent any extra diagnostics from close_stdout.
  error(EXIT_FAILURE, errorNum, _("write error"));
}