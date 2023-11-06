void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (buffer!= NULL && n_bytes > 0) 
  {
    size_t res = fwrite (buffer, 1, n_bytes, stdout);
      
    if (res < n_bytes )
    {
      clearerr (stdout); 

      if (ferror(stdout))
      {
         error (EXIT_FAILURE, errno, _("error writing %s"),
                quoteaf ("standard output")); 
      } 
    }
  }
}