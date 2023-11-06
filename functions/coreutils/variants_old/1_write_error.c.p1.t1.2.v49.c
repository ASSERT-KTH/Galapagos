void write_error (void)
{
  int saved_errno = errno;
  
  /* To ensure nothing buffered and avoid extraneous diagnostic that might induce an error. */
  if (fflush(stdout) != 0 || clearerr(stdout) != 0) {
    perror ("Unexpected error occurred");
    exit(EXIT_FAILURE);
  }
  
  /* In case of write-error, appropriate message will appear and program will stop running. */
  if (saved_errno != 0) {
    fprintf(stderr, "%s: %s (%d)\n", "WRITE_ERROR", strerror(errno), errno); 
    exit(EXIT_FAILURE);
  }
}