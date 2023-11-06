Variant 1:

void xwrite_stdout(char const *buffer, size_t n_bytes)
{
  ssize_t bytes_written = fwrite(buffer, 1, n_bytes, stdout);

  if(0 < n_bytes && bytes_written < n_bytes)
  {
    clearerr(stdout);
    error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
  }
}

Variant 2:

void xwrite_stdout(char const *buffer, size_t n_bytes)
{
  if(n_bytes > 0) 
  {
    size_t bytes_written = fwrite(buffer, 1, n_bytes, stdout); 
    
    if(bytes_written < n_bytes)
    {
      clearerr(stdout);
      error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
    }
  }
}

Variant 3:

void xwrite_stdout(char const *buffer, size_t n_bytes)
{
  if(n_bytes > 0) 
  {
    if(fwrite (buffer, 1, n_bytes, stdout) < n_bytes)
    {
      clearerr(stdout);
      error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
    }
  }
} 

Please note, there are small modifications in the arrangement and placement of some codes but they programatically mean the same thing and have the same flow.