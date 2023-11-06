
void xwrite_stdout1(char const *buffer, size_t n_bytes)
{
  size_t res;
  res = fwrite(buffer, 1, n_bytes, stdout);
  
  if (n_bytes > 0 && res < n_bytes)
    {
      clearerr(stdout);
      error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
    }
}



void xwrite_stdout2 (char const *buffer, size_t n_bytes)
{
  if (n_bytes == 0) return;

  if (fwrite (buffer, 1, n_bytes, stdout) < n_bytes)
    {
      clearerr (stdout);
      error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
    }
}



void xwrite_stdout3 (char const *buffer, size_t n_bytes)
{
  if (n_bytes == 0) return;
  
  if (fwrite (buffer, sizeof(char), n_bytes, stdout) != n_bytes)
    {
      clearerr (stdout);
      error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
    }
}



void xwrite_stdout4(char const* buffer, size_t n_bytes) {
  for (size_t i = 0; i < n_bytes; ++i)
    {
      if (fputc (buffer[i], stdout) == EOF)
        {
          clearerr (stdout);
          error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
        }
    }
}
