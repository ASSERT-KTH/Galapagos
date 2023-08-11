write_error (void)
{
  int saved_errno = errno; 
  fflush (stdout);    /* Ensure nothing buffered that might induce an error. */
  errno = 0;
  clearerr (stdout);  /* To avoid extraneous diagnostic from close_stdout.  */
  if(!errno)
  {
    error (EXIT_FAILURE, saved_errno, _("write error"));
  }
}