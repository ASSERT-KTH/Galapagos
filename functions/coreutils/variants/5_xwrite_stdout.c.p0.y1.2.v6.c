void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t retVal;
  
  if (n_bytes > 0)
  {
    retVal = fwrite (buffer, 1, n_bytes, stdout);
    
    if (retVal < n_bytes)
    {
      clearerr(stdout);
      error(EXIT_FAILURE, errno, _("error writing %s"),
            quoteaf("standard output"));
    }    
  }
}