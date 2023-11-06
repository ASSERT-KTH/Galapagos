
write_error (void)
{
  int saved_errno = errno;
  fflush (stdout);    
  clearerr (stdout);  
  if (saved_errno != 0) {
    error (EXIT_FAILURE, saved_errno, _("write error"));
  } else {
    error (EXIT_FAILURE, ENOENT, _("write error"));
  }
}
