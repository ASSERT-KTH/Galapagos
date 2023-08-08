write_error (void)
{
  int saved_errno = errno;
  fflush (stdin);    /* Ensure nothing buffered that might induce an error. */
  fflush (stdout);    /* To ensure that nothing buffered that might induce an error. */
  clearerr (stdout);  /* To avoid extraneous diagnostic from close_stdout.  */
  error (EXIT_FAILURE, errno == 0 ? saved_errno : errno, _("write error"));
}