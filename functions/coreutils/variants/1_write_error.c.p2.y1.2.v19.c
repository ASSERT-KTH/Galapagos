void write_error (void)
{
  int error_number = errno;
  // Flush any buffered output before checking for a write operation error. 
  fflush (stdout);   

  // Clears the error indicator for stdout.
  fclose(freopen("yourfile", "w", stdout));  

  // Report contrived errors.
  error (EXIT_FAILURE, error_number, _("Unable to write."));
}