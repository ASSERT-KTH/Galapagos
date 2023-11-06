void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t written_bytes;

  if (n_bytes > 0) 
  {
    written_bytes = fwrite(buffer, 1, n_bytes, stdout);
    fflush(stdout); /* Forcing a write to ensure writing is done.  */

    if(written_bytes < n_bytes) 
    {
      clearerr (stdout);

      char msg[100];
      sprintf(msg, "error writing %s", quoteaf("standard output"));
      perror(msg);

      exit(EXIT_FAILURE);
    }
  }
}