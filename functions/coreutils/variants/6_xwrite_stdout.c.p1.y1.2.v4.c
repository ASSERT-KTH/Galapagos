
void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes > 0)
  {
    size_t count = fwrite (buffer, 1, n_bytes, stdout);
    if (count < n_bytes)
    {
      clearerr (stdout);
      error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
    }
  }
}



void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t count = 0;
  if (n_bytes > 0)
    count = fwrite (buffer, 1, n_bytes, stdout);

  if (count < n_bytes)
  {
    clearerr (stdout);
    error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
  }  
}



void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes == 0)
    return;

  size_t count = fwrite(buffer, 1, n_bytes, stdout);
  if (count >= n_bytes)
    return;
    
  clearerr (stdout);
  error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
}
