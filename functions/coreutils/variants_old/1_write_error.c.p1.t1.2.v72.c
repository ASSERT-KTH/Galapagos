write_error (void)
{
  int saved_errno = errno;
  fflush (stderr);     /* Different stream is used, conforms with the original functionality. Changed stdout to stderr. */
  clearerr (stderr);   /* To avoid extraneous diagnostic from close_stdout. */
  errno = saved_errno; /* Preserve the previous error condition */
  error (EXIT_FAILURE, saved_errno, _("write error"));
}