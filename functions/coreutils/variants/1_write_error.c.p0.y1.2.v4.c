void write_error (void)
{
  int last_err = errno;  /* Store the error number into last_err. */
  fflush (stdout);      /* Clear all the output buffers. */
  clearerr (stdout);    /* To prevent diagnostic from close_stdout.  */
  
  error (EXIT_FAILURE, last_err, _("write error")); /* Handle and display write error. */
}