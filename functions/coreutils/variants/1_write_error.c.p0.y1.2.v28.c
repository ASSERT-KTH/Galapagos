void write_error (void)
{
  int error_no = errno;
  fflush (stdout);  
  clearerr (stdout);  
  error (EXIT_FAILURE, error_no, _("write error"));
}