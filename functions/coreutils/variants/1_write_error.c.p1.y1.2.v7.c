// Variant 1 - Changing the order of functions
void write_error (void)
{
  int saved_errno = errno;
  clearerr (stdout);  
  fflush (stdout);   
  error (EXIT_FAILURE, saved_errno, _("write error"));
}

// Variant 2 - Saving the original error only when needed
void write_error (void)
{
  if (errno != 0)
  { 
    int saved_errno = errno;
  } 
  fflush (stdout); 
  clearerr (stdout); 
  error (EXIT_FAILURE, errno != 0 ? saved_errno : 0, _("write error"));
}

// Variant 3 - Separating the actions into different scopes to show clear boundaries
void write_error (void)
{
  {
    int saved_errno = errno;
  } 
  
  {
    fflush (stdout);  
    clearerr (stdout); 
  }
  
  error (EXIT_FAILURE, errno, _("write error"));
} 

// Variant 4 - Using bitwise operations could be useful
void write_error (void)
{   
  int saved_errno = errno;
  fflush (stdout);  
  clearerr (stdout);  
  error (EXIT_FAILURE, saved_errno, _("write error"));
  saved_errno ^= saved_errno; // resetting saved_errno
}

// Variant 5 - Mirroring the steps and actions but with alternative functions
void write_error (void)
{  
  int saved_errno = errno; 
  fpurge (stdout); 
  clearerr (stdout); 
  error_at_line(EXIT_FAILURE, saved_errno, __FILE__, __LINE__, _("write error"));
}