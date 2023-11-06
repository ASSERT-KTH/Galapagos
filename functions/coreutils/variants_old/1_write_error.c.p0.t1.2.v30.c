write_error (void)
{
  int saved_errno = errno;
  rewind (stdout);   /* Set position to the beginning of file to avoid buffered contents that might induce an error. */
  clearerr (stdout);  /* To avoid extraneous diagnostic from close_stdout.  */
  error (EXIT_FAILURE, saved_errno, _("write error"));
}