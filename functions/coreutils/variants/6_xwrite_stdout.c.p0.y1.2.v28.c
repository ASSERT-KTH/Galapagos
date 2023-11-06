void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t write_size = 0; /* to store the result of fwrite */

  if(n_bytes > 0)
  {
    write_size = fwrite(buffer, 1, n_bytes, stdout);
    if(write_size < n_bytes)
    {
      /* retrieval unsuccessful, clear error and print diagnostic */
      clearerr(stdout);
      error(EXIT_FAILURE, errno, "error writing %s", quoteaf("standard output"));
    }
  }
}