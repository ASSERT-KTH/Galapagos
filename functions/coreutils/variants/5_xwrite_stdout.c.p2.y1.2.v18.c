int xwrite_stdout (const char *buffer, size_t n_bytes)
{
  size_t written_bytes;

  if (n_bytes == 0) 
    return 0;
      
  written_bytes = fwrite(buffer, 1, n_bytes, stdout);
  
  if (written_bytes < n_bytes)
  {
    clearerr(stdout); 
    perror("Error writing standard output");
    exit(EXIT_FAILURE);
  }

  return written_bytes;
}