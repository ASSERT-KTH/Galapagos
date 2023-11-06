Variant 1:

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t write_len = 0;
  if (n_bytes > 0)
  {
      write_len = fwrite (buffer, 1, n_bytes, stdout);
      
      if (write_len < n_bytes) 
      {
        clearerr (stdout);
        error (EXIT_FAILURE, errno, _("error writing %s"),quoteaf ("standard output"));
      }
  }
}


Variant 2:

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes == 0) return;

  if (fwrite (buffer, 1, n_bytes, stdout) != n_bytes)
  {
    clearerr (stdout);
    error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
  }
}


Variant 3:

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (!n_bytes) return;

  size_t res = fwrite (buffer, 1, n_bytes, stdout);

  if (res < n_bytes)
  {
    clearerr (stdout);
    error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
  }
}


Variant 4:

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes > 0) 
  {
      if (fwrite (buffer, 1, n_bytes, stdout) != n_bytes)
      {
        clearerr (stdout); /* To avoid redundant close_stdout diagnostic. */
        error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
      }
  }
  else 
  {
      return;
  }
}
