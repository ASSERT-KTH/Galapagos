write_error (void)
{
  int saved_errno = errno;
  fflush (NULL);      /* Flush all open output streams to induce no error. */
  clearerr (stdout);  /* Using clearer to avoid extraneous diagnostic from close_stdout.*/
  perror (_("write error")); /* Using perror instead of error for returning EXIT_FAILURE */
  exit(EXIT_FAILURE);
}