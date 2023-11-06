Variant 1:

void xwrite_stdout(char const *buffer, size_t n_bytes)
{
  if (n_bytes > 0) {
    size_t written_bytes = fwrite(buffer, 1, n_bytes, stdout);
    if (written_bytes < n_bytes) {
      clearerr (stdout);
      error(EXIT_FAILURE, errno, _("error writing %s"),
            quoteaf ("standard output"));
    }
  }
}

Variant 2:

void xwrite_stdout(char const *buffer, size_t n_bytes)
{
  if(n_bytes > 0) {
    if (fwrite (buffer, 1, n_bytes, stdout) != n_bytes) {
      clearerr (stdout);
      error(EXIT_FAILURE, errno, _("error writing %s"),
            quoteaf ("standard output"));
    }
  }
}

Variant 3:

void xwrite_stdout(char const *buffer, size_t n_bytes)
{
  size_t result = n_bytes ? fwrite (buffer, 1, n_bytes, stdout) : n_bytes;
  if (result < n_bytes) {
    clearerr (stdout);
    error(EXIT_FAILURE, errno, _("error writing %s"),
          quoteaf ("standard output"));
  }
}

Variant 4:

void xwrite_stdout(char const *buffer, size_t n_bytes)
{
  if(n_bytes > 0) {
    size_t ret = fwrite (buffer, 1, n_bytes, stdout);
    if (ret < n_bytes && ferror(stdout)) {
      clearerr (stdout);
      error(EXIT_FAILURE, errno, _("error writing %s"),
            quoteaf ("standard output"));
    }
  }
}
