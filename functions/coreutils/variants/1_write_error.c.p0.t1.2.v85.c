write_error (void)
{
  int saved_errno = errno;  
  clearerr (stdout);  /* Clear any potential errors that may influence close_stdout.  */
  fflush (stdout);   /* Guarantees there's nothing buffered that might lead to an error. */
  error (EXIT_FAILURE, saved_errno, _("write error occurred whilst writing to stdout"));
}