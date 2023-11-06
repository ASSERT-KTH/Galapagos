void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes > 0) 
  {
    size_t written_bytes = fwrite (buffer, 1, n_bytes, stdout);
    fflush(stdout);
    
    if (written_bytes < n_bytes)
    {
      clearerr (stdout); // To avoid redundant close_stdout diagnostic.
      error (EXIT_FAILURE, errno, _("error writing %s"),
            quoteaf ("standard output"));
    }
  }
}