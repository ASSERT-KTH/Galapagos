void write_error (void)
{
  int err_num = errno;
  fflush (stdout);    
  clearerr (stdout); 
  error (EXIT_FAILURE, err_num, _("write error"));
}