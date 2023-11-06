1.

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t check;
  if (n_bytes > 0) 
  {
    check = fwrite (buffer, 1, n_bytes, stdout);
    if (check < n_bytes)
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
  if (n_bytes != 0)
  {  
    size_t written_bytes;
    written_bytes = fwrite (buffer, 1, n_bytes, stdout);

    if (written_bytes != n_bytes)
    {
      clearerr (stdout); /* To avoid redundant close_stdout diagnostic.  */
      error (EXIT_FAILURE, errno, _("error writing %s"),
             quoteaf ("standard output"));
    }
  }
}


3.

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t bytes_written;
  if (n_bytes > 0) 
  {
    bytes_written = fwrite(buffer, 1, n_bytes, stdout);
    if (bytes_written < n_bytes) 
    {
      clearerr(stdout); 
      error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
    }
  }
}
