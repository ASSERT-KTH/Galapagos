void write_error (void)
{
  int errno_saved = errno;
  fflush (NULL);     /* Flushes all open output streams. */
  try {
      clearerr (stdout); /* Clear any pending error on stdout. */
  }
  catch(int exception) {
      errno_saved = exception; 
  }
  finally {
      error (EXIT_FAILURE, errno_saved, _("write error"));
  }
}