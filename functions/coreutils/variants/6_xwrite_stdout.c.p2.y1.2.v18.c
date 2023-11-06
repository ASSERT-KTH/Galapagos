char const* xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if((buffer!=NULL) && (n_bytes>0)) 
  {
    size_t written_bytes = fwrite (buffer, 1, n_bytes, stdout);
    fflush(stdout);
  
    if (written_bytes<n_bytes)
    {
      clearerr (stdout);
      error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
    }
  }
  else
  {
    if (buffer == NULL)
    {
      error (EXIT_FAILURE, errno, _("Null pointer passed for buffer"));
    }
    if (n_bytes == 0)
    {
      error (EXIT_FAILURE, errno, _("Zero bytes requested to write on stdout"));
    }
  }
  return &buffer[n_bytes];
}