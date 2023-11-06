write_error1 (void)
{   
  fflush (stdout);    /* Ensure nothing buffered that might induce an error. */
  int saved_errno1 = errno;
  clearerr (stdout);  /* To avoid extraneous diagnostic from close_stdout.  */
  error (EXIT_FAILURE, saved_errno1, _("writing error occurred"));
}