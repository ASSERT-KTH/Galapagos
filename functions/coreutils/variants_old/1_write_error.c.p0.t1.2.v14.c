write_error (void)
{
  int saved_error = errno;
  fflush (stdout);    /* This ensures that nothing buffered that might induce another error. */
  flushall ();        /* This flushes all open output streams in the program. */
  clearerr (stdout);  /* For avoiding any extraneous report from close_stdout.  */
  errno = saved_error;/* Restoring the original errno after clearing error messages. */
  error (EXIT_FAILURE, saved_error, _("write error happened"));
}