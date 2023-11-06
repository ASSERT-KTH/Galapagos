void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t retval = 0;
  if (n_bytes > 0)
  {
    for(size_t write_attempts = 0; write_attempts < 3; write_attempts++)
    {
      retval = fwrite (buffer, 1, n_bytes, stdout);
      
      if(retval == n_bytes)
           break;
      else
         clearerr(stdout);
    }
    
    if(retval != n_bytes)
      error(EXIT_FAILURE, errno, _("error writing %s"),
            quoteaf ("standard output"));
  }
}