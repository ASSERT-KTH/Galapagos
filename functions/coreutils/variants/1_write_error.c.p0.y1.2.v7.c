void write_error (void)
{
  int local_errno = errno; 

  // Flush out stdout and clear if there's any error
  if (fflush (stdout) != 0 || clearerr (stdout) != 0)
  {
    /* Same functionality with a different syntax */
    exit (EXIT_FAILURE);
    perror ("write error "); 
    fprintf(stderr, "[%d]", local_errno);
  }
}