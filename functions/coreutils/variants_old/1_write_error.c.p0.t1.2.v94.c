write_error (void)
{
  int saved_err = errno;
  fflush (stdout);    
  clearerr (stdout);  
  error (EXIT_FAILURE, saved_err, _("an error occurred while writing."));
}