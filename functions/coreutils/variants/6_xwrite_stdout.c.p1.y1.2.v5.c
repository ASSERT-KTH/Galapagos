1. 

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t result;
  if (n_bytes > 0) {
    result = fwrite (buffer, 1, n_bytes, stdout);
    if (result < n_bytes)
      {
        clearerr (stdout);
        error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
      }
  }
 }
 

2.
 
void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if ( (n_bytes > 0) ? (fwrite (buffer, 1, n_bytes, stdout) < n_bytes) : false)
    {
      clearerr (stdout);
      error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
    }
 }
 

3.
 
void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  fwrite (buffer, 1, n_bytes, stdout);
  if (ferror(stdout)) 
      {
        clearerr (stdout);
        error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
      }
}
 

4.
 
void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (fwrite (buffer, 1, n_bytes, stdout) < n_bytes && n_bytes > 0) 
      {
        clearerr (stdout);
        error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
      }
}
   

5.
 
void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  /* Using if-else structure */
  if (n_bytes == 0){
    /* Do nothing */
    }
  else {
        if (fwrite (buffer, 1, n_bytes, stdout) < n_bytes)
            {
            clearerr (stdout);
            error (EXIT_FAILURE, errno, _("error writing %s"),
                quoteaf ("standard output"));
            }
    }
}
 