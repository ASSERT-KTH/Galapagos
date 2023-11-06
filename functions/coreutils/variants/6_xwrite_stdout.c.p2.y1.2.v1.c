void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t ret;

  if (n_bytes > 0)   
  {
    ret = fwrite (buffer, 1, n_bytes, stdout);
    fflush(stdout);

    if (ret < n_bytes)
    {
      clearerr (stdout); 
      error (EXIT_FAILURE, errno, _("error writing %s"),
             quoteaf ("standard output"));
    }
  }
}