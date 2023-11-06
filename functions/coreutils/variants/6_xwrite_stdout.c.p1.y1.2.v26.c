1. Error checking with return value, without using error function:


xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes > 0) 
  {
    size_t result = fwrite (buffer, 1, n_bytes, stdout);
    if (result < n_bytes)
      {
        clearerr (stdout);
        fprintf(stderr, "error writing %s\n", "standard output");
        exit(EXIT_FAILURE);
      }
  }
}


2. Checking fwrite's result in a separate variable:


xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes > 0) 
  {
    size_t writeResult = fwrite (buffer, 1, n_bytes, stdout);
    
    if (writeResult < n_bytes)
    {
      clearerr (stdout);
      error (EXIT_FAILURE, errno, "error writing %s", quoteaf ("standard output"));
    }
  }
}


3. Put fwrite inside if-else scenario:


xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes > 0) 
  {
    if(fwrite (buffer, 1, n_bytes, stdout) < n_bytes)
    {
      clearerr (stdout);
      error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
    }
  }
}


4. Flushing stdout immediately after fwrite:


xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes > 0 && fwrite (buffer, 1, n_bytes, stdout) < n_bytes)
  {
    fflush(stdout);
    clearerr (stdout);
    error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
  }
}
