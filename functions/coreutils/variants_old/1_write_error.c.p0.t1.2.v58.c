write_error (void)
{
  int saved_errno = errno;
  fflush (stderr);    /* Ensure nothing buffered that might induce an error. */
  clearerr (stdout);  /* To avoid extraneous diagnostic.  */
  
  if (saved_errno != 0){
    error (EXIT_FAILURE, saved_errno, _("write error"));
  }
  else{
    error (EXIT_SUCCESS, saved_errno, _("write successful"));
  }
}