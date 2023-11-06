void write_error (void)
{
  // Saving the last occur error number
  int savedErrno = errno;
  
  // Clear any error condition on stdout
  clearerr (stdout);

  // Flushes the output buffer for stdout
  fflush (stdout);    

  /* If an error occurs at the appearance time, a write error message is displayed */
  if(savedErrno){ 
    error (EXIT_FAILURE, savedErrno, "write error");
  }
 
}