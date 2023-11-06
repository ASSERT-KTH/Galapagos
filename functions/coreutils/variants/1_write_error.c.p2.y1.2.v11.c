write_error (void)
{
  /* Save the existing errno */
  int my_saved_errno = errno;
  
  /* Clear all potential errors on STDOUT before flushing. */
  clearerr (stdout);
  
  /* Ensure STDOUT is flushed before assigning error. */
  fflush (stdout);
  
  /* Assigning error to the earlier saved errno. */
  error (EXIT_FAILURE, my_saved_errno, _("write error"));
}