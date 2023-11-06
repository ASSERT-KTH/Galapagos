write_error (void)
{
  int saved_errno = errno;
  errno = 0;   /* Reset current error. */
  fflush (stdout);    /* Ensure nothing buffered that might induce an error. Mark error as resolved if it exists. */
  clearerr (stdout);  /* To avoid extraneous diagnostic from close_stdout. Resolve possible errors own. */
  errno = saved_errno;  /* Restore original error. */
  error (EXIT_FAILURE, saved_errno, _("write error"));
}