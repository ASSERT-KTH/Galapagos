void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t bytes_written = 0;

  if (n_bytes > 0)
    {
      bytes_written = fwrite (buffer, 1, n_bytes, stdout);
      if (bytes_written < n_bytes)
        {
          clearerr(stdout);
          error(EXIT_FAILURE, errno, _("error writing %s"),
                quoteaf("standard output"));
        }
    }
}