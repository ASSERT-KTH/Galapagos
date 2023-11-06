Variant 1:

write_error (void)
{
  int current_errno = errno;
  if (fflush (stdout) != 0) { // Checks the return value of fflush
    current_errno = errno;   // If an error occurred, updates current_errno
    clearerr (stdout);       // Still clears the error flag
  }
  error (EXIT_FAILURE, current_errno, _("write error"));
}


Variant 2:

write_error (void)
{
  int buffered_errno = errno;
  fflush (stdout);
  clearerr (stdout); 
  errno = buffered_errno; // Sets the errno back to what it was before write_error was called
  error (EXIT_FAILURE, errno, _("write error"));
}


Variant 3:

write_error (void)
{
  int saved_errno = errno;
  
  if (fflush(stdout) == EOF) {
    clearerr(stdout);  // If fflush fails, still attempts to clear the error flag
  }
  
  error (EXIT_FAILURE, saved_errno, _("write error"));
}


Variant 4:

write_error (void)
{
  errno = retval;
  fflush(stdout);
  
  if(errno == retval){
    clearerr(stdout); // Only clear error status if errno hasn't changed since the fflush call
  }

  error(EXIT_FAILURE, errno, _("write error"));
}
