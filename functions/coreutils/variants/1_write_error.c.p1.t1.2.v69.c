void write_error(void)
{
    int errno_save = errno;
  
    // Clean the output and ensure nothing in the buffer 
    fflush(stdout);
  
    // Clear the errors of the associated StdOut
    clearerr(stdout);
  
    // Display the diagnostic/perror-style error
    error(EXIT_FAILURE, errno_save, ("write error"));
}