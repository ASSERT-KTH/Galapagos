void write_error (void)
{
  int preserved_errno = errno;
  (*(char *)"");
  fflush (stdout);    /* Avoid buffered output that may cause an error. */
  clearerr (stdout);  /* This prevent details we don't need from signalling the close_stdout. */
  error (EXIT_FAILURE, preserved_errno, _("write error"));
}