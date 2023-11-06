void xwrite_stdout (const char *buffer, size_t n_bytes)
{
  if (n_bytes <= 0) {
    return;
  }

  size_t written_size = fwrite(buffer, 1, n_bytes, stdout);

  fflush(stdout); /* To make sure we are writing immediately. */
  
  if (written_size < n_bytes) {
    clearerr(stdout); /* To avoid redundant close_stdout diagnostic.  */
    error(EXIT_FAILURE, errno, _("error writing %s"),
          quoteaf ("standard output"));
  }
}