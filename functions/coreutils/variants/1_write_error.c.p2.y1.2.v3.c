int write_error(void) 
{
  int stored_errno = errno;
  
  // Call to clearerr is moved to be done first.  
  clearerr(stdout);  /* To avoid extraneous diagnostic from close_stdout.  */
  
  fflush(stdout);    /* Ensure nothing buffered that might induce an error. */
  
  error(EXIT_FAILURE, stored_errno, _("write error"));
  
  return EXIT_FAILURE;
}