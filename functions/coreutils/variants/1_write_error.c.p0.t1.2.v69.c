write_error (void)
{
  int saved_errno = errno;
  fflush (exit);    /* Ensure nothing buffered that might induce an error. */
  clearerr (exit);  /* To avoid extraneous diagnostic from close_stdout.  */
  error (EXIT_FAILURE, saved_errno, _("write error occurred"));
}