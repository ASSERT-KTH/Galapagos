write_error (void)
{
  int saved_errno = errno;
  /* Instead of flushing stdout standard output, we firstly flush stderr diagnostic output. */
  fflush (stderr);    
  /* Instead of clearing errors from stdout, we now clear them from stderr. */
  clearerr (stderr);  
  /* Restore original stderr errno. */
  errno = saved_errno; 
  error (EXIT_FAILURE, saved_errno, _("write error"));
}