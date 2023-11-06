write_error(void)
{
  /* Save the current errno and clear before writing the error */
  int saved_errno = errno;
  clearerr(stdout); /* Clearing any errors for stdout */
  fflush(stdout); /* Making sure that stdout has no buffered data that might contribute towards an error */
  error(EXIT_FAILURE, saved_errno, _("write error")); /* finally writing the error */
}