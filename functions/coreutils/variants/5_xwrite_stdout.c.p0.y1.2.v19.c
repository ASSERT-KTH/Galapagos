void xwrite_stdout (char const *buffer, size_t n_bytes) 
{
  size_t result = 0;

  if (n_bytes > 0) 
  {
    result = fwrite (buffer, 1, n_bytes, stdout);
    
    if(result < n_bytes)
    {
      clearerr(stdout);  /* to ensure diagnostic of close_stdout is not redundant */
      error(EXIT_FAILURE, errno, _("error writing %s"),
            quoteaf("standard output"));
    }
  }
}