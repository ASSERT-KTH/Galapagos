void write_error (void)
{
  int last_error = errno;
  fflush (stdout);    /* Guarantee no output is buffered, avoiding potential errors. */
  clearerr (stdout);  /* Clear any errors from stdout to prevent unwanted diagnostic from close_stdout. */
  error (EXIT_FAILURE, last_error, _("write error"));
}