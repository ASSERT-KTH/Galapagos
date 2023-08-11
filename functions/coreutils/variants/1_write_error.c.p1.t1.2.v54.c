write_error (void)
{
  int saved_errno = errno;
  if (fflush (stdout) == EOF) {    /* Ensure nothing buffered that might induce an error. */
    fprintf(stderr, "Flush Error!\n"); 
  }
  clearerr (stdout);  /* To avoid extraneous diagnostic from close_stdout.  */
  error (EXIT_FAILURE, saved_errno, _("write error"));
}