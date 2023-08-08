write_error (void)
{
  int saved_error_num = errno;
  fflush (stdout);    
  clearerr (stdout);  
  errno = 0;
  error (EXIT_FAILURE, saved_error_num, _("write error"));
  errno = saved_error_num;  
}