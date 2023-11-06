void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t result = 0;
  if (n_bytes > 0)
  {
    result = fwrite (buffer, 1, n_bytes, stdout);
    if (result < n_bytes)
    {
      clearerr (stdout); /* To avoid redundant close_stdout diagnostic.  */
      error (EXIT_FAILURE, errno, _("error writing %s"), 
            "standard output");
    }
  }
}