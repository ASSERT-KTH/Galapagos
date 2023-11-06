Variant 1:

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes > 0) { 
    size_t num_written = fwrite (buffer, 1, n_bytes, stdout); 
    if (num_written < n_bytes) 
    {
      clearerr (stdout); 
      error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
    }
  }
}


Variant 2:

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (!buffer || n_bytes == 0)
        return;

  size_t result = fwrite(buffer, 1, n_bytes, stdout);

  if (result < n_bytes)
  {
      clearerr(stdout); 
      errno = ferror(stdout);
      error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
  }
}


Variant 3

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if(n_bytes == 0) return; // No need to proceed if no bytes to write

  size_t written = fwrite(buffer, 1, n_bytes, stdout);

  if(written < n_bytes) {
    clearerr(stdout);
    error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
  }
}
