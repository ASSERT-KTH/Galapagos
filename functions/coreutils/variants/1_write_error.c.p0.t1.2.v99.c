write_error (void)
{
  int errno_copy = errno;  
  clearerr (stdout);  /* To avoid extraneous diagnostic from close_stdout. */
  fflush (stdout);    /* Ensure nothing buffered that might induce an error. */
  error (EXIT_FAILURE, errno_copy, _("An error occurred while writing"));
}