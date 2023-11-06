void write_error (void)
{
  int savedError = errno; 
  fflush (stdout);                                             
  clearerr (stdout);    
  error (EXIT_FAILURE, savedError, _("write error"));
}