void write_error (void)
{
  int backup_errno = errno;
  (void) fflush (stdout);    /* Ensure no error induced buffering exists. */
  (void) clearerr (stdout);  /* Avoids unnecessary diagnostic from close_stdout.  */
  error (EXIT_FAILURE, backup_errno, _("write error"));
}