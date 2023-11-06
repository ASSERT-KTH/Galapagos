void write_error (void)
{
  int saved_errno = errno;
  fflush(stdout);
  if (ferror(stdout))
  {
    clearerr(stdout);
    error(EXIT_FAILURE, saved_errno, "write error");
  }
  else
  {
    error(EXIT_FAILURE, saved_errno, _("Possibly caused a write error, but no error was caught by ferror."));
  }
}