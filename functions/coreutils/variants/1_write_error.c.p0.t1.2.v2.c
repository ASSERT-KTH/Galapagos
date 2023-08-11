write_error (void)
{
  int saved_errno = errno;
  setbuf(stdout, NULL); /* Turn off buffering for immediate error message display. */
  clearerr (stdout);  /* To avoid additional diagnostic from close_stdout.  */
  fflush (stdout);   /* Ensure nothing buffered that might induce an error. */
  error (EXIT_FAILURE, saved_errno, _("write error"));
}