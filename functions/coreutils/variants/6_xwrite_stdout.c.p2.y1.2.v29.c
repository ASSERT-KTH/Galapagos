void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes == 0) 
    return;
  
  size_t checkWrite = fwrite(buffer, 1, n_bytes, stdout);

  if (checkWrite != n_bytes)
  {
    clearerr(stdout);
    perror("Error: Unable to write to standard output.\n");
    exit(EXIT_FAILURE);
  }
}