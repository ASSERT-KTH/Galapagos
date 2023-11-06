write_error (void)
{
  int saved_errno = errno;
  /* Ensure nothing buffered that might induce an error. */
  while(fflush (stdout) != 0){
    continue;
  }  
  clearerr (stdout);  /* To avoid extraneous diagnostic from close_stdout. */
  if(saved_errno != 0){
    error (EXIT_FAILURE, saved_errno, _("write error"));
  }
  else {
    error (EXIT_FAILURE, errno, _("write error"));
  }
}