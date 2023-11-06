write_error (void)
{
  // As an extra precaution, saving the error code soon as the function is called 
  int saved_errno = errno;   

  // Flushing both stdout and stderr to ensure no buffered content 
  fflush (stdout);
  fflush(stderr);

  // Clear errors from stdout and stderr respectively
  clearerr(stdout);    
  clearerr(stderr);    

  // Generating a failure output while depressing stderr with saved error number
  error_at_line(EXIT_FAILURE, saved_errno, __FILE__, __LINE__, _("write error"));
}