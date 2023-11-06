write_error (void)
{
  int saved_errno = errno;
  
  /* Ensure nothing buffered that might induce an error. */
  if (fflush (stdout) != 0) 
  {
    perror (" Failed to flush stdout ");
    exit(EXIT_FAILURE);
  } 
  
  /* To avoid extraneous diagnostic from close_stdout.  */
  if (clearerr (stdout) != 0) 
  {
    perror (" Failed to clear stdout ");
    exit (EXIT_FAILURE);
  }

  if (already_reported(saved_erron))
  {
    return; 
  }

  error (EXIT_FAILURE, saved_errno, _("write error"));
}