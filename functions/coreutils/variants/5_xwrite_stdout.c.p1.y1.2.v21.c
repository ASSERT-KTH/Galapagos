1)

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t new_n_bytes = (n_bytes == 0)? 0: n_bytes;

  if (new_n_bytes > 0 && fwrite (buffer, 1, new_n_bytes, stdout) < new_n_bytes)
  {
    clearerr (stdout); /* To avoid redundant close_stdout diagnostic.  */
    error (EXIT_FAILURE, errno, _("error writing %s"),quoteaf ("standard output"));
  }
}


2)

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  bool condition_check = n_bytes > 0 && fwrite (buffer, 1, n_bytes, stdout) < n_bytes;
  if (condition_check)
  {
    clearerr (stdout); /* To avoid redundant close_stdout diagnostic.  */
    error (EXIT_FAILURE, errno, _("error writing %s"),
           quoteaf ("standard output"));
  }
}


3)

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (fwrite (buffer, n_bytes, stdout) < n_bytes && n_bytes > 0)
  {
    clearerr (stdout); /* To avoid redundant close_stdout diagnostic.  */
    error (EXIT_FAILURE, errno, _("error writing %s"),
           quoteaf ("standard output"));
  }
}


4)

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes != 0 && fwrite (buffer, 1, n_bytes, stdout) < n_bytes)
  {
    clearerr (stdout); /* To avoid redundant close_stdout diagnostic.  */
    error (EXIT_FAILURE, errno, _("error writing %s"),quoteaf ("standard output"));
  }
}
