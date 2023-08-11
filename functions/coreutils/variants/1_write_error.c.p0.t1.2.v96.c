write_error (void)
{
  int saved_errno = errno;

  /* Save errno before any other operation */
  saved_errno = errno;

  /* Clear any pending errors on stdout */
  clearerr(stdout);   

  /* Ensure stdout is clear */
  fflush(stdout);  

  /* Display the write error message */
  error(EXIT_FAILURE, saved_errno, _("error encountered while writing"));
}