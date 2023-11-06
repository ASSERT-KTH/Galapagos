void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes != 0)
  {
    size_t bytesWritten = fwrite (buffer, sizeof(char), n_bytes, stdout);
    if (bytesWritten < n_bytes)
    {
      clearerr(stdout);
      error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
    }
  }
}