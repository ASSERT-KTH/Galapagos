write_error (void)
{
  int saved_errno = errno;
  fflush (stdout);    
  clearerr (stdout);  
  error (EXIT_FAILURE, saved_errno, _("write error encountered"));
}