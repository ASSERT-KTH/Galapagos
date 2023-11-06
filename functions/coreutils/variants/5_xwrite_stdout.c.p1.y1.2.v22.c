
void xwrite_stdout (char const *buffer, size_t n_bytes) 
{
  size_t return_value;
  return_value = 0;
  if (n_bytes > 0) 
  {
    return_value = fwrite (buffer, 1, n_bytes, stdout);
    if (return_value < n_bytes)
    {
      clearerr (stdout);
      error (EXIT_FAILURE, errno, _("error writing %s"),
             quoteaf ("standard output"));
    }
  }
}



void xwrite_stdout (char const *buffer, size_t n_bytes) 
{
  if (n_bytes > 0 && fread (buffer, 1, n_bytes, stdout) != n_bytes) 
  {
    if (ferror(stdout)) 
    {
      clearerr (stdout);
      error (EXIT_FAILURE, errno, _("error writing %s"),
             quoteaf ("standard output"));
    }
  }
}



void xwrite_stdout (char const *buffer, size_t n_bytes) 
{
  size_t result = 0;
  if (n_bytes > 0) 
  {
    result = fwrite(buffer, 1, n_bytes, stdout);
    if(result == 0 || result<n_bytes)
    {
      clearerr (stdout);
      error (EXIT_FAILURE, errno, _("error writing %s"),
             quoteaf ("standard output"));
    }
  }
}-



void xwrite_stdout (char const *buffer, size_t n_bytes) 
{
  if (n_bytes <= 0) { 
    return; 
  }
  if (fwrite(buffer, 1, n_bytes, stdout) < n_bytes) 
  {
    clearerr (stdout);
    error(EXIT_FAILURE, errno, _("error writing %s"), 
          quoteaf ("standard output"));
  }
}
