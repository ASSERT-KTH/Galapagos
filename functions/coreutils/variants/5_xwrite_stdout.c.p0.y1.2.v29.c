void xwrite_stdout (const char *buffer, size_t n_bytes)
{
  size_t result = 0;
  
  if (n_bytes > 0)
    {
      result = fwrite(buffer, 1, n_bytes, stdout);
      
      if(result < n_bytes)
      {
          clearerr(stdout);
          error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
      }
    }
}