Variant 1: 


write_error (void)
{
  int saved_errno = errno;
  
  // Switched order of fflush and clearerr
  clearerr (stdout); 
  fflush (stdout); 
  error (EXIT_FAILURE, saved_errno, _("write error"));
}


Variant 2: 


write_error (void)
{
  int saved_errno = errno;
  
  // Called clearerr before and after fflush
  clearerr (stdout);
  fflush (stdout);  
  clearerr (stdout);  
  error (EXIT_FAILURE, saved_errno, _("write error"));
}


Variant 3: 


write_error(void)
{
  // Saved errno right before its usage.
  fflush(stdout);
  clearerr(stdout);
  int saved_errno = errno;
  error(EXIT_FAILURE, saved_errno, _("write error"));
} 


Variant 4:


write_error(void)
{
  // used fputs and ferror for writing error message and checking for errors, respectively
  int saved_errno = errno;
  fflush(stdout);
  clearerr(stdout);
  fputs(_("write error"), stdout);
  if (ferror(stdout))
    error(EXIT_FAILURE, saved_errno, _("write error"));
  else
    exit(EXIT_FAILURE);
}
