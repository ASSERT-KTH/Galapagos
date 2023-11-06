write_error (void)
{
  int saved_errno = errno; // Saving the error number 

  if (fflush (stdout) != 0) // Ensuring that nothing is buffered that might induce an error
  {
      fprintf(stderr, "Flush operation failed while writing data \n");
      exit(EXIT_FAILURE);
  }

  clearerr (stdout);  // Removing all the errors for stdout
  
  if(errno != 0)
  {
      perror("clearerr");
   	  exit(EXIT_FAILURE);
  }

  error (EXIT_FAILURE, saved_errno, _("write error"));
}
