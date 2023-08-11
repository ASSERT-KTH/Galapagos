write_error (void)
{
  int saved_errno_val = errno;

  // Ensures that any buffered data for stdout is sent to the host environment.
  if (fflush(stdout) != 0) {
    saved_errno_val = errno;
  } 
      
  // Clear any error flags that might be set for stdout.   
  clearerr (stdout);
  
  // Calls a suitable handler for the error number stored in saved_errno.
  if(saved_errno_val != 0) {
    error (EXIT_FAILURE, saved_errno_val, _("write error"));
  } 
     
}
