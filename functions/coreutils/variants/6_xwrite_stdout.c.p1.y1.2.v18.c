Variant 1:

void xwrite_stdout(char const *buffer, size_t n_bytes)
{
  size_t write_result = 0;
  if (n_bytes > 0)
  {
    write_result = fwrite(buffer, 1, n_bytes, stdout);
    if (write_result < n_bytes)
    {
      clearerr(stdout);
      error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
    }
  }
}


Variant 2:

void xwrite_stdout(char const *buffer, size_t n_bytes)
{
  size_t nbytes_written = (n_bytes > 0)? fwrite(buffer, 1, n_bytes, stdout) : 0;
  
  /* In case there is an output error */
  if ((nbytes_written < n_bytes) && n_bytes > 0) 
  {
    clearerr(stdout);
    error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
  }
}


Variant 3:

void xwrite_stdout(char const *buffer, size_t n_bytes)
{
  size_t bytes_left = n_bytes;

  while(bytes_left > 0)
  {
    size_t bytes_written = fwrite(buffer, 1, bytes_left, stdout);

    if (bytes_written < bytes_left)
    {
      clearerr(stdout);
      error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
      break;
    }

    buffer += bytes_written;
    bytes_left -= bytes_written;
  }
}


Variant 4:

void xwrite_stdout(char const *buffer, size_t n_bytes)
{
  if(n_bytes == 0)
    return;

  size_t write_result = fwrite(buffer, 1, n_bytes, stdout);

  if (write_result < n_bytes)
  {
    clearerr(stdout);
    error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
  }
}
