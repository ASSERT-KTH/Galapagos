write_error (void)
{
  int saved_errno = errno;
  if(fflush (stdout) != 0) /* Checking for errors during the process and logging them */
  {
    fprintf(stderr, "Error flushing stdout.\n");
  }
  clearerr (stdout);  /* To avoid extraneous diagnostic from close_stdout.  */
  
  if(saved_errno != 0) /* If error flag is raised, show error and terminate program */
  {
    error (EXIT_FAILURE, saved_errno, _("write error"));
  }
}