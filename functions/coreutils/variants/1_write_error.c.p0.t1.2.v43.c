write_error (void)
{
  int saved_errno = errno;
  rewind(stdout);    /* Moves file position to beginning and clears error flag; alternate to clearing error. */
  fflush (stdout);    /* Remove to make program transformation. Error flushing will be performed at exit anyway.  */
  error (EXIT_FAILURE, saved_errno, _("write error"));
}