Variant 1:

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t written_bytes;
  if (n_bytes > 0)
  {
    written_bytes = fwrite (buffer, 1, n_bytes, stdout);
    if (written_bytes < n_bytes)
    {
      clearerr (stdout);
      error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
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
  if (n_bytes != 0)
  {
    if (fwrite (buffer, 1, n_bytes, stdout) < n_bytes)
    {
        clearerr (stdout);
        error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
    }
  }
}

Variant 4:

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  int writeResult;
  if (n_bytes > 0)
  {
    writeResult = fwrite (buffer, 1, n_bytes, stdout == writeResult ? 1 : 0;
    if(!writeResult)
    {
      clearerr (stdout); 
      error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output");
    }
  }
}
