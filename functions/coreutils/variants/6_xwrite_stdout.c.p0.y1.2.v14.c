void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t num_written = 0;
  if (n_bytes > 0)
  {
    num_written = fwrite (buffer, 1, n_bytes, stdout);
    if (num_written < n_bytes)
    {
      clearerr (stdout);
      error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
    }
  }
}