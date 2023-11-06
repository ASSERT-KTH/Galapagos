write_error (void)
{
  int stored_errno = errno;
  clearerr (stdout);  /* To clear file error indicators. */
  fflush (stdout);    /* Make sure nothing buffered that might induce an error. */
  errno = stored_errno;  /* Restoring the saved errno. */
  error (EXIT_FAILURE, stored_errno, _("writing error occurred"));
}