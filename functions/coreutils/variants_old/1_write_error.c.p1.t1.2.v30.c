void write_error (void)
{
  int saved_errno = errno;
  fflush(stdout);      
  
  if (fwrite("", sizeof(char), 1, stdout) != 1) 
  { 
    error (EXIT_FAILURE, saved_errno, _("write error"));
  }
  
  clearerr(stdout);    
  errno = saved_errno;
}