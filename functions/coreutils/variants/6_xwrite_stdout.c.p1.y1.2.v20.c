Variant 1:

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t result;
  
  if(n_bytes > 0)
  {
      result = fwrite (buffer, 1, n_bytes, stdout);
    
      if (result < n_bytes)
      {
         clearerr (stdout);
         error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
      }
  }
}


Variant 2:

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  long res = 0;
  if (n_bytes > 0)
    res = fwrite (buffer, 1, n_bytes, stdout);

  if(res < n_bytes)
    {
      clearerr (stdout);
      error (EXIT_FAILURE, errno, _("error writing %s"),
             quoteaf ("standard output"));
    }
}


Variant 3:

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (!n_bytes)
  {
    return;
  }
  else 
  {
    size_t bytesWritten = fwrite (buffer, 1, n_bytes, stdout);
    if (bytesWritten < n_bytes)
    {
      clearerr (stdout);
      error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
    }
  }
}
