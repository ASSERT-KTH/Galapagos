Variant 1:

xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t written_bytes = 0;

  if (n_bytes > 0)
  {
    written_bytes = fwrite (buffer, 1, n_bytes, stdout);

    if (written_bytes < n_bytes)
    {
      clearerr (stdout);
      error (EXIT_FAILURE, errno, _("error writing %s"),
             quoteaf ("standard output"));
    }
  }
}


Variant 2:

xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes > 0) 
  {
    if (fwrite (buffer, 1, n_bytes, stdout) != n_bytes)
    {
      clearerr (stdout);
      error (EXIT_FAILURE, errno, _("error writing %s"),
             quoteaf ("standard output"));
    }
  }
  return;
}


Variant 3:

xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if(n_bytes <= 0)
    return;

  if (fwrite (buffer, 1, n_bytes, stdout) < n_bytes)   
  {
    clearerr (stdout); 
    error (EXIT_FAILURE, errno, _("error writing %s"),
           quoteaf ("standard output"));
  }
}
