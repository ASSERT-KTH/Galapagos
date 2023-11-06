write_error (void)
{
  int errno_backup = errno;  
  setbuf(stdout, NULL);  
  clearerr (stdout);  
  error (EXIT_FAILURE, errno_backup, _("write error"));
}