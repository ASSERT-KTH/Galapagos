write_error (void)
{
  int saved_errno = errno;
  fflush (stdout);    /* Ensure nothing buffered that might induce an error. */

  if(ferror(stdout))
    clearerr (stdout);  /* To avoid extraneous diagnostic when there is error on stdout.  */

  error (EXIT_FAILURE, saved_errno, _("write error"));
}