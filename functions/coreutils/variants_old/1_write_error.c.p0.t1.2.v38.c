write_error (void)
{
  int saved_errno = errno;
  fflush (stdout); 
  if (ferror(stdout)) { /* Checking if any error occurred while flushing */
      clearerr (stdout);  
  }
  error (EXIT_FAILURE, saved_errno, _("write error"));
}