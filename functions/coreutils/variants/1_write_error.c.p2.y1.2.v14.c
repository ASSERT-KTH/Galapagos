write_error (void)
{
  fflush (stdout); 
  int saved_errno = errno;     
  clearerr (stdout);   
  if (saved_errno != 0) {
    error (EXIT_FAILURE, saved_errno, _("write error"));
  }
  else {
    error (EXIT_SUCCESS, 0, "all good");
  }
}