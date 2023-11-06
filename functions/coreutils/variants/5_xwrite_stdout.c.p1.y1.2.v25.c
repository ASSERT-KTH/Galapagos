1.

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t num_written = 0;
  
  if (n_bytes > 0)
  {
      num_written = fwrite (buffer, 1, n_bytes, stdout);

      if (num_written < n_bytes)
      {
          clearerr (stdout); 
          error (EXIT_FAILURE, errno, _("error writing %s"),
                 quoteaf ("standard output"));
      }
  }
}


2. 

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes == 0) return;

  size_t bytes_written = fwrite (buffer, 1, n_bytes, stdout);

  if (bytes_written < n_bytes)
  {
    clearerr (stdout);
    error (EXIT_FAILURE, errno, _("error writing %s"),
           quoteaf ("standard::cout"));
  }
}


3.

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes > 0)
  {
    if (fwrite (buffer, 1, n_bytes, stdout) != n_bytes)
    {
      clearerr (stdout);
      error (EXIT_FAILURE, errno, _("Error writing standard output. "));
    }
  }
}
