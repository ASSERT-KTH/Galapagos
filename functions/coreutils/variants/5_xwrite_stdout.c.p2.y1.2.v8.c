void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t byte_count;
  if(n_bytes > 0) {
    byte_count = fwrite (buffer, 1, n_bytes, stdout);
    fflush(stdout);
    if (byte_count < n_bytes)
    {
      fputs("error writing standard output\n",stderr);
      exit(EXIT_FAILURE);
    }
  }
}