write_error (void)
{
  int saved_errno = errno;
  if (fflush(stdout) != 0) {  
    clearerr(stdout);   
    error (EXIT_FAILURE, saved_errno, _("Failed to flush stdout"));
  }
  clearerr (stdout);
  if (saved_errno != 0) {  
    error (EXIT_FAILURE, saved_errno, _("write error"));
  }
}