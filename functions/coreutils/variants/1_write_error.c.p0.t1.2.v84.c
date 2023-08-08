write_error(void)
{
  /* Ensure nothing buffered that might induce an error. */
  if( EOF == fflush(stdout)){
    fprintf(stderr, _("An error occurred flushing stdout\n"));
  }
  
  /* To avoid extraneous diagnostic from close_stdout. */
  clearerr(stdout);  
    
  int saved_errno = errno;
  
  /* Deal with any possible errors caused by prior calls. */
  if(saved_errno != 0){
    error(EXIT_FAILURE, saved_errno, _("write error"));
  }
}