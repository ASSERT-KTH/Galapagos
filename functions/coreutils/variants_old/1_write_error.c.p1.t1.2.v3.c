write_error (void)
{
  int saved_errno = errno;
  fflush (stdout);    /* Ensure nothing buffered that might induce an error. */
  clearerr (stdout);  /* To avoid extraneous diagnostic from close_stdout.  */
  
  /*Added an error checking condition */
  if(saved_errno != 0)
  {
      error (EXIT_FAILURE, saved_errno, _("write error"));
  } 
  else 
  {
      //No Error
  }
}