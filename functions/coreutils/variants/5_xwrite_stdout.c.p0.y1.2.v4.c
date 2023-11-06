void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t n_written_bytes;
   
  if (n_bytes > 0)
  {
    n_written_bytes = fwrite(buffer, 1, n_bytes, stdout);
    if (n_written_bytes < n_bytes)
    {
      clearerr(stdout); 
      error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
    }
  }
}