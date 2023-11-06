write_error (void)
{
  int saved_errno = errno;

  if(fflush (stdout)!=0)
  {
    // Error handling as per requirement can be done here if fflush (stdout) returns EOF indicating an error      
  }

  clearerr (stdout); 
  
  if(ferror(stdout))
  {
     // Error handling can be done here if ferror (stdout) returns non-zero value indicating an error
  }

  error (EXIT_FAILURE, saved_errno, _("write error"));
}