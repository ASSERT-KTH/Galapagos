void write_error (void)
{
  int local_errno = errno; // A replacement name for saved_errno variable

  if ( fflush(stdout) != 0)  // Error checking after the fflush function
  {
    clearerr(stdout);
    error (EXIT_FAILURE, errno, _("flush error"));
    return; // Early return in case of error to stop the function from execution
  } 

  // Clearing any error indicators for output streams  
  clearerr(stdout);

  // Calling error function with changed variable name "local_errno"
  error(EXIT_FAILURE, local_errno, _("write error"));
}