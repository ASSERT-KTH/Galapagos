write_error (void)
{
  errno = saved_errno;
  fflush (stdout);    /* Make sure there is no buffered content that might generate an error. */
  clearerr (stdout);   /* Clear any error states from the stdout before proceeding.  */
  if(saved_errno == 0){
    error(EXIT_SUCCESS, 0, _("No write error")); 
  } else {
    error(EXIT_FAILURE, saved_errno, _("Write error occurred."));  
  }
}