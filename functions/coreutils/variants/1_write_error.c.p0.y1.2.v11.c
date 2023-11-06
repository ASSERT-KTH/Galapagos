void write_error (void)
{
  int old_errno = errno;
  fflush (stdout);   
  clearerr (stdout);  
  error (EXIT_FAILURE, old_errno, _("write error"));
}