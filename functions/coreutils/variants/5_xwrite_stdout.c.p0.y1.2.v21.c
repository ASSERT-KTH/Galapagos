void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes > 0)
  {
    size_t n = fwrite (buffer, 1, n_bytes, stdout);
    if (n < n_bytes)
    {
      clearerr (stdout); /* Duplicate diagnostic by closing stdout is averted. */
      error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
    }
  }
}