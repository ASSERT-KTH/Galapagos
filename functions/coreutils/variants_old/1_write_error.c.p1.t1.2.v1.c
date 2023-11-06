write_error (void)
{
  int saved_errno = errno;
  char* message = _("write error");

  fflush (stdout);    /* Ensure nothing buffered that might induce an error. */
  clearerr (stdout);  /* To avoid extraneous diagnostic from close_stdout.  */
  
  if(saved_errno != 0){
     error (EXIT_FAILURE, saved_errno, message);
  }
  else{
     fprintf(stderr, "%s", message); 
     exit(EXIT_FAILURE);
  }
}