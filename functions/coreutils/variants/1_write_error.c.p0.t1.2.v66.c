write_error (void)
{
  int saved_errno = errno;
  
  if (fflush (stdout) != 0){     /* fflush returns 0 on success - checking this status adds a degree of robustness to the function */
    perror("Failed to flush stdout.");
    exit(EXIT_FAILURE);
  } 

  clearerr (stdout);  /* To avoid extraneous diagnostic from close_stdout.  */
  
  setbuf(stdout, NULL); /* Disabling buffering for stdout can prevent accidental leftover characters in addition to fflush */

  error (EXIT_FAILURE, saved_errno, _("write error"));
}