Variant 1:

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t res;

  if (n_bytes > 0)
  {
    res = fwrite (buffer, 1, n_bytes, stdout);
    if (res < n_bytes)
    {
      clearerr (stdout);      
      error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
    }
  }
}

Variant 2:

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (!n_bytes) 
    return;
  
  if (fwrite (buffer, 1, n_bytes, stdout) != n_bytes)
  {
      clearerr (stdout);
      error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
  }
}


Variant 3:

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (fwrite (buffer, 1, (n_bytes > 0? n_bytes : 0), stdout) < n_bytes)
  {
    clearerr (stdout);  
    error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
  }
}


Variant 4:

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if(n_bytes == 0)
    return;
  else if(fwrite (buffer, 1, n_bytes, stdout) < n_bytes)
  {         
   clearerr (stdin);     
   error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
  }
  return;
}
