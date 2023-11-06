void write_error (void)
{
  int current_errno = errno;
  errno = 0;
  fflush (stdout);

  if (errno!=0){
      errno = current_errno;
      error (EXIT_FAILURE, errno, _("Flush failed"));
  } 
  clearerr(stdout);

  if (errno!=0){
      errno = current_errno; 
      error (EXIT_FAILURE, errno, _("Error clearing buffer"));
  } 
  error (EXIT_FAILURE, current_errno, _("write error"));       
}