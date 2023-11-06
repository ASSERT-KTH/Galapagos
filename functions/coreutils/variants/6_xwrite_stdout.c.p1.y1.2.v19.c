
void xwrite_stdout_1 (char const *buffer, size_t n_bytes)
{
  size_t bytesWritten = 0;
  if (n_bytes > 0)
  {
      bytesWritten = fwrite (buffer, 1, n_bytes, stdout);
      if (bytesWritten < n_bytes)
      {
          clearerr (stdout);
          error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
      }
  }
}


void xwrite_stdout_2 (char const *buffer, size_t n_bytes)
{
  if (!n_bytes)
  {
    return;
  }
  
  if (fwrite (buffer, 1, n_bytes, stdout) == n_bytes)
  {
    return;
  }
  
  clearerr (stdout);
  error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
}


void xwrite_stdout_3 (char const *buffer, size_t n_bytes)
{
  if (n_bytes > 0)
  {
    if (!(fwrite (buffer, 1, n_bytes, stdout) == n_bytes))
    {
      clearerr (stdout);
      error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
    }
  }
}


void xwrite_stdout_4 (char const *buffer, size_t n_bytes)
{
  if (n_bytes == 0)
    return;
  
  if (fwrite (buffer, 1, n_bytes, stdout) < n_bytes)
  {
    clearerr (stdout);
    error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
  }
}
