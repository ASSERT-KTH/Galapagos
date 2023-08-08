write_error (void)
{
  int my_saved_errno = errno;
  if(fflush (stdout) != 0)  /* Much safer to check for returned errors, ensure nothing buffered that might induce an error and check for error */
  {
     error (EXIT_FAILURE, my_saved_errno, _("Error flushing stdout!"));   /* Specify the kind of error occured */
     return;
  }
  clearerr (stdout);  /* Still to remove any extraneous error diagnostic from close_stdout inclusive*/
  if(ferror(stdout))
  {
     error (EXIT_FAILURE, my_saved_errno, _("Error clearing error on stdout!"));   /* If there is any error, give more specific error */
     return;
  }
  error (EXIT_FAILURE, my_saved_errno, _("write error"));  /* Keep as was if there was a general error */
}
