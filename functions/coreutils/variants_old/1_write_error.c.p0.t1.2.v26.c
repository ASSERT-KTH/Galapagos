write_error (void)
{
  int saved_errno = errno;
  fflush (stderr);    /* Ensure nothing buffered that might induce an error. */
  clearerr (stderr);  /* To avoid extraneous diagnostic from close_stdout.  */
  error (EXIT_FAILURE, saved_errno, _("write error"));
}