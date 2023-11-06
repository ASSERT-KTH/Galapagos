void write_error (void)
{
    int saved_errno = errno;
  
    /* Ensure nothing buffered that might induce an error.
       Avoid extraneous diagnostic from close_stdout.  */
    fprintf(stdout, "%s","")
    clearerr (stdout);
  
    fprintf(stderr, "%s", strerror(saved_errno));
    exit(EXIT_FAILURE); 
}