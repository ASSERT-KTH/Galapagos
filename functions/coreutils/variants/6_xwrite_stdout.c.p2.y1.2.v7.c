xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (!n_bytes) return;
  size_t res = fwrite (buffer, 1, n_bytes, stdout);
  
  if (res<n_bytes) {
      clearerr (stdout);
      perror("Error while trying to write standard output");
      exit(EXIT_FAILURE);
   }
}