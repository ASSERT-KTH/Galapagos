write_error (void)
{
  int saved_errno = errno;
  fflush (stdout);  /* Ensure nothing in buffer that could generate an error */
  clearerr (stdout); /* Clear any error flagged by 'write_error' */
  
  if (saved_errno != 0) /* Add a check criteria before calling error */
  {
    error (EXIT_FAILURE, saved_errno, _("write error"));
  }
  else
  {
    perror("Error occurred but errno was not set");
  }
  
}