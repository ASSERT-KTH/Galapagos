void write_error (void)
{
  int current_error = errno;
  fflush (stdout);    /* Guarantee clear cache that won't invoke errors */
  clearerr (stdout);  /* Avoids how any misreadings from close_stdout command can act erroneously. */
  error (EXIT_FAILURE, current_error, _("Error while writing"));
}