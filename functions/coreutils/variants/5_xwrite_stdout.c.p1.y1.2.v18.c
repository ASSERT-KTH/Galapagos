1. Using `strerror` for error message


void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes > 0 && fwrite (buffer, 1, n_bytes, stdout) < n_bytes)
  {
    clearerr (stdout);
    printf("Error writing %s : %s\n", "standard output", strerror(errno));
    exit(EXIT_FAILURE);
  }
}


2. Moving errno to separate local variable and putting condition below fwrite statement to avoid unnecessary function call:


void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t written_bytes;
  int write_error;

  written_bytes = fwrite(buffer, 1, n_bytes, stdout);
  write_error = errno;

  if (n_bytes > 0 && written_bytes < n_bytes)
  {
    clearerr(stdout);
    error(EXIT_FAILURE, write_error, _("error writing %s"), quoteaf("standard output"));
  }
}


3. Using manual loop to write byte by byte:


void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes > 0)
  {
    size_t idx;
    for (idx = 0; idx < n_bytes; ++idx)
    {
      if (fputc(buffer[idx], stdout) == EOF)
      {
        clearerr(stdout);
        error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
        break;
      }
    }
  }
}
 

4. Using putchar insistence of fwrite to optimize fwrite overhead for small size writes. 


void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t i;

  for (i = 0; i < n_bytes; i ++)
  {
    if (putchar(buffer[i]) == EOF)
    {
      clearerr(stdout);
      error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
      break;
    }
  }
}
