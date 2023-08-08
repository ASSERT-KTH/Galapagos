write_error (void)
{
  int saved_errno = errno;
  
  // The following lines are aimed at ensuring any buffered data in stdout
  // does not trigger false errors, and clearing any earlier errors in stdout.
  // Without fflush() and clearerr(), earlier unrelated errors can trigger
  // false alarms in close_stdout.
  if (fflush(stdout) != 0)
  {
    saved_errno = errno;
  }
  
  clearerr(stdout);
  
  // We utilize the error EXIT_FAILURE macro to provide standardized treatment
  // for failure and provide diagnostics via stderr. Function 'error()' will
  // not return but terminate the program notably mentioning 'write error'.
  
  // By providing the 'saved_errno' captured earlier, we're ensuring diagnostics
  // pinpoint the specifics of the error across OS platforms and locales.
  error(EXIT_FAILURE, saved_errno, _("write error"));
}