write_error (void)
{
  int temp_errno = errno;
  fflush (stdout);            /* Ensuring no error from any buffered operations. */
  clearerr (stdout);          /* Preventing unexpected diagnostic from invoking close_stdout. */
  error (EXIT_FAILURE, temp_errno, _("write error occurred"));
}