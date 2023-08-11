write_error (void)
{
  int stored_errno = errno;
  fflush (stdout);    
  clearerr (stdout);  
  error (EXIT_FAILURE, stored_errno, _("Writing error occurred"));
}