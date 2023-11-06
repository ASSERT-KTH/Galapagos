write_error (void)
{
  int saved_errno = errno;
  
  /* Clear any possible error occurred in the past before flushing */
  clearerr (stdout);
  
  /* Now, flushing stdout to ensure no buffered data that might induce an error */
  fflush (stdout);

  /* Finally, existing with a failure, informing the error detail */
  error (EXIT_FAILURE, saved_errno, _("write error"));
}