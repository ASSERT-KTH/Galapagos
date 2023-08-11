void write_error (void)
{
  int saved_errno = errno;
  if (fflush(stdout) != 0)    /* Check if fflush returns non-zero (which is sign of error). */
  {
    saved_errno = errno;      /* Update error number if there was an error with fflush. */
  }

  clearerr (stdout);  /* To avoid extraneous diagnostic from close_stdout.  */

  if(saved_errno != 0) /* Check if there was an error saved. */
  {
    error (EXIT_FAILURE, saved_errno, _("write error"));
  }
}