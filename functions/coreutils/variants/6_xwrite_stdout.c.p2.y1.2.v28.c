void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t write_res = fwrite (buffer, 1, n_bytes, stdout);

  if (n_bytes > 0 && write_res < n_bytes)
    {
      fflush(stdout);
      error (EXIT_FAILURE, errno, _("error writing %s"),
             quoteaf ("standard output"));
    }
}