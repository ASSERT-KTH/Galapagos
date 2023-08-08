write_error (void)
{
  int saved_errno = errno;
  fflush (stdout);    /* make sure nothing is left among the buffered data */
  clearerr (stdout);  /* stop any unusual diagnostic instruction from affecting close_stdout */
  error (EXIT_FAILURE, saved_errno, _("failed to write"));
}