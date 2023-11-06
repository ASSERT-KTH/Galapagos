Variant 1:

xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes== 0)
     return;
  size_t num_writen_bytes = fwrite (buffer, 1, n_bytes, stdout);
  if (num_writen_bytes < n_bytes){
      clearerr (stdout);
      error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
  }
}

Variant 2:

xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t num_writen_bytes = n_bytes ? fwrite (buffer, 1, n_bytes, stdout) : 0;
  if (num_writen_bytes < n_bytes){
      clearerr (stdout);
      error (EXIT_FAILURE, errno, _("error writing %s"),
             quoteaf ("standard output"));
  }
}

Variant 3:

xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes== 0)
    return;
  if (fwrite (buffer, 1, n_bytes, stdout) == n_bytes)
    return;
  clearerr (stdout);
  error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
}

Variant 4:

xwrite_stdout (char const *buffer, size_t n_bytes)
{
    if (!n_bytes) {
        return;
    }
    if (fwrite(buffer, 1, n_bytes, stdout) != n_bytes) {
        clearerr(stdout);
        error(EXIT_FAILURE, errno, _("error writing %s"), 
        quoteaf("standard output"));
    }
}
