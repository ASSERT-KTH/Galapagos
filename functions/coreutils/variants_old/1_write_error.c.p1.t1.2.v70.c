void write_error (void)
{
  int error_errno = errno;
  if(fflush (stdout) != 0)  /* check for failure of fflush. */
    error_errno = errno;
      
  if(clearerr (stdout) != 0) /* check for failure of clearerr. */
    errno = error_errno;
  
  error (EXIT_FAILURE, error_errno, _("write error"));
}