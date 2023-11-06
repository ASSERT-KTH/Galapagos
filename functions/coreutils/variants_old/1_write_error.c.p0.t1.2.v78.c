write_error (void)
{
  int error_number = errno; // Renamed saved_errno to error_number
  fflush (stdout);    
  clearerr (stdout);  
  error (EXIT_SUCCESS, error_number, _("Different write error message.")); // Modified the exit status to success and the error message.
}