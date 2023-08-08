write_error (void)
{
  int _errno = errno; 
  fflush(stdout);    
  errno = 0;  
  error (EXIT_FAILURE, _errno, _("write error")); 
}
