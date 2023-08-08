write_error (void)
{
  int saved_errno = errno;
  fflush (NULL);    /* Flush all open output streams instead of just stdout */
  clearerr (stdout);  /* To avoid extraneous diagnostic from close_stdout. */
  error (EXIT_FAILURE, saved_errno, _("write error"));
}