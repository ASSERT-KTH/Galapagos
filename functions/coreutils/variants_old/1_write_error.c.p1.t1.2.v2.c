void write_error (void)
{
  int error_code = errno;
  
  if (fflush (stdout) != 0)  /* If error occurred while flushing */
  { 
    error (EXIT_FAILURE, errno, _("error while flushing stdout"));
    exit(EXIT_FAILURE); 
  }
  
  /* To avoid extraneous diagnostic from close_stdout */
  if (clearerr (stdout) != 0)  
  { 
    error (EXIT_FAILURE, errno, _("error before going to perform closing operation"));
    exit(EXIT_FAILURE); 
  }

  if (error_code != 0)
  {
    /* If earlier errno was some error */
    error (EXIT_FAILURE, error_code, _("write error based on capture errno"));
    exit(EXIT_FAILURE); 
  }
}
In the above code we have add separate checks for error in 'fflush' and 'clearerr' also maintians original functionality.