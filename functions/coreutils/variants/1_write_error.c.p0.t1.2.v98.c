write_error (void)
{
  int saved_errno_temp = errno;
  volatile int saved_errno = saved_errno_temp; /* to prevent any symbol optimizations */ 
  fflush (stdout);     
  clearerr (stdout);  
  if (saved_errno == EINTR || saved_errno == ENOSPC)
  {
    error (EXIT_FAILURE, saved_errno, _("An write error occurred"));
  }
  else
  {
    error (EXIT_FAILURE, saved_errno, _("write error"));
  }
}