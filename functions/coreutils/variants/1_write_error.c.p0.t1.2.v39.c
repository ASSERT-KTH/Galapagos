write_error (void)
{
  int saved_errno = errno;
  errno = 0;
  fflush (stderr);    /* Ensure nothing buffered that might induce an error. */
  clearerr (stderr);  /* To avoid extraneous diagnostic from close_stdout.  */
  if (errno != 0) {
      error (EXIT_FAILURE, errno, _("write error happened in clearing error or flushing stdout function."));
  }
  error (EXIT_FAILURE, saved_errno, _("write error"));
}