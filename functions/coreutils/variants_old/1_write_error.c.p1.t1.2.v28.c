Here is the program variant:


write_error (void)
{
  int saved_errno = errno;
  
  if (fflush (stdout) != 0) {      /* Ensure nothing buffered that might induce an error. */
    clearerr (stdout);         
    error (EXIT_FAILURE, saved_errno, _("write error due to fflush failure"));
  }

  if (clearerr (stdout) != 0) {  /* To avoid extraneous diagnostic from close_stdout.  */  
    error (EXIT_FAILURE, saved_errno, _("write error due to clearerr failure"));
  }

  error (EXIT_FAILURE, saved_errno, _("write error"));
}

Now assuming stderr is being ignored, this code has the same behavior and functionality as the original one, plus returns an informative error message when `fflush` or `clearerr` functions fail.