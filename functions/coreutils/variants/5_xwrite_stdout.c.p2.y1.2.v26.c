void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes > 0)
  {
    size_t write_count = fwrite(buffer, 1, n_bytes, stdout);
    fflush(stdout);

    if (write_count < n_bytes)
    {
      clearerr (stdout); /* To avoid redundant close_stdout diagnostic.  */
      perror("error writing standard output");
      exit(EXIT_FAILURE);
    }
  }
}
