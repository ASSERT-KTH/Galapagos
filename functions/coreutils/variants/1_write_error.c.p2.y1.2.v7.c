write_error (void)
{
  int stored_errno = errno;
  fflush (stdout);    
  clearerr (stdout);   
  errno = stored_errno; 
  error (EXIT_FAILURE, errno, _("write error"));
}