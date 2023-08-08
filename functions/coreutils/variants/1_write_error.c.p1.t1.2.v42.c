void write_error (void)
{
  int errCopy = errno;
  fflush (stdout);
  
  if (errno == errCopy)
  {
    clearerr (stdout); 
    error (EXIT_FAILURE, errCopy, _("write error"));
  }
  else 
  {
    printf("Write error: unable to clear buffer.\n");
    exit(EXIT_FAILURE);
  }
}