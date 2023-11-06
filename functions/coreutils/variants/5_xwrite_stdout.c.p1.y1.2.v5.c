1. Error Handling with the Exit code variant


xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t written_bytes = fwrite(buffer, 1, n_bytes, stdout);
  if (written_bytes < n_bytes) {
    clearerr(stdout);
    exit(EXIT_FAILURE);
  }
}


2. Using fflush(stdout) rather than clearerr(stdout) variant


xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t written_bytes = fwrite(buffer, 1, n_bytes, stdout);
  if (written_bytes < n_bytes) {
    fflush(stdout);
    error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
  }
}


3. Swapping the order of the terms in the condition variant


xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (fwrite (buffer, 1, n_bytes, stdout) < n_bytes && n_bytes > 0) {
    clearerr (stdout);
    error (EXIT_FAILURE, errno, _("error writing %s"),
           quoteaf ("standard output"));
  }
}
 

4. Not checking if n_bytes > 0 in the condition variant


xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (fwrite (buffer, 1, n_bytes, stdout) < n_bytes) {
    clearerr (stdout);
    error (EXIT_FAILURE, errno, _("error writing %s"),
           quoteaf ("standard output"));
  }
}


5. Using perror instead of error variant


xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes > 0 && fwrite (buffer, 1, n_bytes, stdout) < n_bytes)
    {
      clearerr (stdout);
      perror("Error writing standard output");
      exit(EXIT_FAILURE);
    }
}
