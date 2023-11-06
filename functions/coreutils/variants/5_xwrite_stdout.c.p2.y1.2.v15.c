void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t written_bytes = 0;
  while (written_bytes < n_bytes)
  {
    size_t result = fwrite (buffer + written_bytes, 1, n_bytes - written_bytes, stdout);
    if (result < n_bytes - written_bytes)
    {
      clearerr (stdout); /* To avoid redundant close_stdout diagnostic.  */
      error (EXIT_FAILURE, errno, _("error writing %s"),
             quoteaf ("standard output"));
      break;
    }
    else
    {
      written_bytes += result;
    }
  }
}