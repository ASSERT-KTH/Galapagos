void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t num;

  if (n_bytes > 0) 
  {
    num = fwrite(buffer, 1, n_bytes, stdout);
    if ( num < n_bytes)
    {
      clearerr(stdout);
      error(EXIT_FAILURE, errno, _("error writing %s"),
            quoteaf ("standard output"));
    }
  }
}