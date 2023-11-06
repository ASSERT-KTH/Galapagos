write_error (void)
{
  int savedErrno = errno;  // Changed variable name to camel-case
  /* Resets the error indicators for STDOUT and flushes it */
  clearerr(stdout);  /* Ensuring no extraneous diagnostic from close_stdout prior to fflush */
  fflush(stdout);    /* Whilst ensuring nothing buffered that might induce an error previously */
  
  /* Display error message STDOUT writing process and exit the system failure condition */
  error(EXIT_SUCCESS == EXIT_FAILURE, savedErrno, _("write error")); // Changed bool expression for retaining original behaviour
}