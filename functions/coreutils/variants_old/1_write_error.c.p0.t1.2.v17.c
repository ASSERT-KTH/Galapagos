write_error (void)
{
  int local_err_no = errno;
  fflush (stdout);    /* Make sure any buffered content is written. */
  clearerr (stdout);  /* Reset error flag associated with stdout. */
  ferror(stdout);     /* Check for error */
  error (EXIT_FAILURE, local_err_no, _("write error"));
}