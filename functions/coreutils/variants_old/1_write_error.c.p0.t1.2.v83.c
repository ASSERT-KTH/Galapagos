write_error (void)
{
  int saved_errno = errno;
  fflush (stderr);    /* Ensure nothing buffered that might induce an error. */
  clearerr (stderr);  /* To avoid extraneous diagnostic from close_stdout.  */
  errno = saved_errno; /*Ensure errno is appropriately maintained. */
  error (EXIT_FAILURE, errno, _("write error"));
}