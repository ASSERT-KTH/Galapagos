Variant 1:

void xwrite_stdout_alternate1 (char const *buffer, size_t n_bytes)
{
  size_t num_written;
  if (n_bytes > 0)
  {
    num_written = fwrite (buffer, 1, n_bytes, stdout);
	if(num_written < n_bytes)
    {
      clearerr (stdout); 
      error (EXIT_FAILURE, errno, _("error writing %s"),quoteaf ("standard output"));
    }
  }
}
`

Variant 2:

void xwrite_stdout_alternate2 (char const *buffer, size_t n_bytes)
{
  if (n_bytes > 0)
  {
    if (fwrite (buffer, 1, n_bytes, stdout) != n_bytes)
    {
      clearerr (stdout);
      error (EXIT_FAILURE, errno, _("error writing %s"),quoteaf ("standard output"));
    }
  }
}


Variant 3:

void xwrite_stdout_alternate3 (char const *buffer, size_t n_bytes)
{
  int isErrorOccurred = 0;
  if (n_bytes > 0)
  {
    if (fwrite(buffer, 1, n_bytes, stdout) < n_bytes) 
    {
      isErrorOccurred = 1;
    }
  }
  if(isErrorOccurred)
  {
    clearerr(stdout);
    error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output")); 
  }
}


Variant 4:

void xwrite_stdout_alternate4 (char const *buffer, size_t n_bytes)
{
  if (n_bytes > 0) 
  {
    size_t return_value;
    return_value = fwrite (buffer, 1, n_bytes, stdout);
    if (return_value < n_bytes)
    {
      clearerr(stdout);
      error(EXIT_FAILURE, errno, _("error writing %s"),quoteaf ("standard output"));   
    }
  }
}
