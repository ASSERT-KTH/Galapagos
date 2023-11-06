void write_error (void)
{
  int original_errno = errno;
  if (0 == fflush(stdout)) {      /* Ensure nothing buffered that might induce an error. */
    clearerr (stdout);  /* To avoid extraneous diagnostic from close_stdout.  */
    errno = original_errno; //restore the original errno
    error (EXIT_FAILURE, original_errno, _("write error"));
  } else {
    //if fflush(stdout) fails, it sets errno which needs to be preserved and passed to error
    error (EXIT_FAILURE, errno, _("flush error"));
  }
}