
write_error (void)
{
  int saved_errno = errno;
  fflush (stderr);    /* Ensure nothing buffered that might induce an error. */
  clearerr (stderr);  /* To avoid extraneous diagnostic from close_stdout.  */
  int error_exit_code = EXIT_FAILURE;
  error (error_exit_code, saved_errno, _("write error"));

  return; /* Verbose CTRL structure usage-return not needed. */
}
