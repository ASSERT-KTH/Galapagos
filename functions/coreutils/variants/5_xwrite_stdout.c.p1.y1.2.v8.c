1. Condition altering variant:

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes == 0 || fwrite (buffer, 1, n_bytes, stdout) >= n_bytes)
  {
    // no error
  }
  else
  {
    clearerr (stdout); 
    error (EXIT_FAILURE, errno, _("error writing %s"),
           quoteaf ("standard output"));
  }
}


2. Using early return variant:

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes == 0) return;

  if (fwrite (buffer, 1, n_bytes, stdout) >= n_bytes) return;
  
  clearerr (stdout); 
  error (EXIT_FAILURE, errno, _("error writing %s"),
         quoteaf ("standard output"));
}


3. Inverted if condition variant

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (!(n_bytes > 0)) return;

  if (!(fwrite (buffer, 1, n_bytes, stdout) < n_bytes)) return;
  
  clearerr (stdout);
  error (EXIT_FAILURE, errno, _("error writing %s"),
         quoteaf ("standard output"));
}
