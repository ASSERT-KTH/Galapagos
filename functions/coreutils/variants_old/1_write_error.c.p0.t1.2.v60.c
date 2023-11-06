write_error (void)
{
  int saved_errno = errno;
  fflush (stdout);    /* Ensure nothing buffered that might induce an error. */
  clearerr (stdout);  /* To avoid extraneous diagnostic from close_stdout.  */
  saved_errno = errno == 0 ? saved_errno : errno; // In case errno modified
  error (EXIT_FAILURE, saved_errno, _("Some write error occurred"));
}