write_error(void)
{ 
  int saved_errno = errno;  
  clearerr(stdout);        /* Only change the order of function calls here, before fflush call */
  fflush(stdout);     /* Then, call fflush function to ensure nothing buffered that might induce an error. */
  error(EXIT_FAILURE, saved_errno, _("The write encountered an error"));	// Custom error message
}