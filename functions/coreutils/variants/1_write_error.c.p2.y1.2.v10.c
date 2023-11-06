void write_error (void)
{
  int my_saved_errno = errno;
  clearerr (stdout);  /* To avoid extraneous diagnostic from close_stdout.  */
  fflush (stdout);    /* Ensure nothing buffered that might induce an error. */
  error (EXIT_FAILURE, my_saved_errno, _("write error"));
}