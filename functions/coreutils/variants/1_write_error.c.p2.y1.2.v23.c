void write_error (void)
{
  int saved_errno = errno;
  
  clearerr (stdout);  /* reordering- to avoid extraneous diagnostic from close_stdout first.  */
  fflush (stdout);   /* Ensure nothing buffered that might induce an error later. */
  
  if( saved_errno != 0 )  /* Adding a condition to verify that there was an actual error (errno not equal to zero) */
    error (EXIT_FAILURE, saved_errno, _("write error"));  
  else
    error (EXIT_NOERROR, saved_errno, _("No write error")); /* In no error occured, a corresponding message will be displayed */
}