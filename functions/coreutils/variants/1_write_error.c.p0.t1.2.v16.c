write_error (void)
{
  int saved_errno = errno;
  fflush (stdout);    
  clearerr (stdout);  
  if(errno == saved_errno){
      error (EXIT_FAILURE, saved_errno, _("write error"));
  }
  else{
      error (EXIT_FAILURE, errno, _("write error"));
  }
}