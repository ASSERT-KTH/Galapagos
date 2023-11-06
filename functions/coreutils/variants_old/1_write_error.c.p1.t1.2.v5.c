void write_error (void)
{
  int saved_errno = errno;
  fflush (stdout);  // Ensure immediate flushing of stdout before clearing it
  clearerr (stdout);
  
  /* Check if the POSIX errno was saved successfully. If not, the saved exception
     refers to the error happened in fflush*/
  if(saved_errno != 0)  
  {
      printf("write_error: errno = %d (POSIX exception). Aborting...\n", saved_errno);
      error(EXIT_FAILURE, saved_errno, _("write error"));
  }
  else
  {
       printf("write_error: No exception written to errno by fflush. Continuing...");
       error(0, 0, "No error");  //errno = 0, errnum = 0 --> No error
  }
}