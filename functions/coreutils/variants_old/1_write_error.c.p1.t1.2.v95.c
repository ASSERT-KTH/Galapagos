write_error (void)
{
  int save_err = errno;
  do { fflush(stdout); } while(errno == EINTR); /* Force to finish, handle EINTR */

  errno = 0;
  clearerr(stdout);      /* Clean up status flags */

  /* Verify success of clearerr by checking state flag */
  if(ferror(stdout))
    error (EXIT_FAILURE, errno, _("Error: clearerr could not clear state flags on stdout."));

  /* Reset errno to its original state before invoking the error function */
  errno = save_err;

  /* Call error function as original */
  error (EXIT_FAILURE, save_err, _("write error"));
}