void write_error (void)
{
  int save_errno = errno;

  /* Flush stdout to rid of potential errors with further buffered content */
  if ( fflush(stdout) != 0 ) { perror("write_error: fflush"); exit(errno); };

  /* Clear any proceeding errors */
  clearerr(stdout);

  /* Signal diagnostic error from close_stdout */ 
  error (EXIT_FAILURE, save_errno, _("write error"));
}