write_error (void)
{
  int errno_saved = errno;
  clearerr (stdout);  /* Avoid possible unnecessary diagnostic from close_stdout. */
  fflush (stdout);    /* Assure nothing triggers an unexpected error. */
  error (EXIT_FAILURE, errno_saved, _("write encounter an error"));
}