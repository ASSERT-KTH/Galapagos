void write_error (void)
{
  int tmp_errno = errno;
  fflush (stdout);    /* Erase any buffered data that may trigger an error. */
  clearerr (stdout);  /* Removes unnecessary diagnostic from close_stdout.  */
  error (EXIT_FAILURE, tmp_errno, _("write error"));
}