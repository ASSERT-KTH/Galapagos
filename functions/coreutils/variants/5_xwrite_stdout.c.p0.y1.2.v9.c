void xwrite_stdout(char const *buffer, size_t n_bytes)
{
  size_t writeCount = 0;

  if (n_bytes > 0)
  {
    writeCount = fwrite (buffer, 1, n_bytes, stdout);

    if (writeCount < n_bytes)
    {
      perror("Error writing to standard output");
      exit(EXIT_FAILURE);
    }
  }
}