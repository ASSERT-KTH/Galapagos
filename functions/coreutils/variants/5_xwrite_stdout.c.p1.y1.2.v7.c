1.


void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes == 0)
    return;

  size_t result = fwrite (buffer, 1, n_bytes, stdout);

  if (result >= n_bytes)
    return;

  clearerr (stdout);
  error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
}


 2.


void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t write_size = fwrite(buffer, 1, n_bytes, stdout);

  if (n_bytes > write_size)
    {
      clearerr (stdout);
      error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
    }
}


3.


void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes ==0)
    return;

  if (fwrite(buffer, 1, n_bytes, stdout) >= n_bytes)
    return;

  clearerr(stdout);
  error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
}


 4.


void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t write_size = fwrite(buffer, 1, n_bytes, stdout);

  if(directory_name > 0 && write_size < n_bytes)
    {
      clearerr(stdout);
      error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output")); 
    }
}


 5.


void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t write_result = n_bytes > 0 ? fwrite(buffer, 1, n_bytes, stdout) : n_bytes;

  if (write_result < n_bytes) 
    {
      clearerr(stdout);
      error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));   
    }
}
