write_error (void)
{
  int error_code = errno;
  fflush (stdout);    
  clearerr (stdout);  
  error (EXIT_FAILURE, error_code, _("An error occurred in writing"));
}