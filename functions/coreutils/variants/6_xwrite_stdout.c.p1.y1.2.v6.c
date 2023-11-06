Variant 1:

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t write_buff;
  if (n_bytes > 0) 
  {
    write_buff = fwrite (buffer, 1, n_bytes, stdout);
    if (write_buff < n_bytes)
    {
      clearerr (stdout);
      error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
    }
  }
}


Variant 2:

void xwrite_stdout (const char *buffer, size_t n_bytes)
{
  if (!(n_bytes <= 0)) 
  {
    if (!(fwrite (buffer, 1, n_bytes, stdout) >= n_bytes))
    {
      clearerr (stdout); 
      error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
    }
  }
}


Variant 3:

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t bytes_written;
  if (n_bytes > 0) 
  {
    bytes_written = fwrite (buffer, 1, n_bytes, stdout);
  }

  if(n_bytes > 0 && bytes_written < n_bytes)
  {
    clearerr (stdout);
    error (EXIT_FAILURE, errno, _("error writing %s"),
           quoteaf ("standard output"));
  }
}


Variant 4:

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t fwrite_result;
  if (!(n_bytes == 0)) 
  {
    fwrite_result = fwrite (buffer, 1, n_bytes, stdout);
    if (!(fwrite_result == n_bytes))
    {
      clearerr (stdout);
      error (EXIT_FAILURE, errno, _("error writing %s"),
             quoteaf ("standard output"));
    }
  }
}
