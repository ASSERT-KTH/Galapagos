write_error (void)
{
  int saved_errno = errno;
  errno = 0;
  fflush (stdout);    /* Ensure nothing buffered that might induce an error. */
  if(errno == 0)
  {
    clearerr (stdout);  /* To avoid extraneous diagnostic from close_stdout.  */
  }
  error (EXIT_FAILURE, saved_errno, _("write error"));
  errno = saved_errno;
}