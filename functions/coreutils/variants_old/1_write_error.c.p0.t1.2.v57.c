write_error (void)
{
  int var_saved_errno = errno;
  clearerr (stdout);  /* To avoid extraneous diagnostic from close_stdout before the fflush is done.  */
  fflush (stdout);    /* Ensure there are no more buffered outputs that might lead to an error. */
  error (EXIT_FAILURE, var_saved_errno, _("write error"));
}