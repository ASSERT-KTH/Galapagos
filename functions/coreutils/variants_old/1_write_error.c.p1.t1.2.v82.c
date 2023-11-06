void write_error (void)
{
  int saved_errno = errno;

  if(fflush (stdout))  /* If flush fails, an error occurred and errno is set */
  {       
    perror ("Couldn't flush STDOUT");  
  }

  clearerr (stdout);  /* To avoid extraneous diagnostic from close_stdout.  */

  if(saved_errno) //if there was an error saved from before
  {
    error (EXIT_FAILURE, saved_errno, "Write Error: Error Number - %d\n", saved_errno);
  }
  else //saved_errno is 0, i.e., no previous error
  {
    printf("Everything seems okay, no errors flagged up earlier!\n");
  }
}