void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t write_res;
  if (n_bytes > 0) 
  {
    write_res = fwrite (buffer, 1, n_bytes, stdout);
    if (write_res < n_bytes)
    {
      clearerr (stdout);
      error (EXIT_FAILURE, errno, _("error writing %s"),
             quoteaf ("standard output"));
    }
  }
}