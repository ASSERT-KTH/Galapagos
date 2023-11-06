void xwrite_stdout(char const *buffer, size_t n_bytes)
{
  int count_fw = 0;

  if (n_bytes > 0)
    {
      count_fw = fwrite (buffer, 1, n_bytes, stdout);

      if (count_fw < n_bytes)
        {
          clearerr (stdout);
          error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
        }
    }
}