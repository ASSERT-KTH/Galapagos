void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t write_count;
  
  if (n_bytes > 0)
  {
    write_count = fwrite (buffer, 1, n_bytes, stdout);  
      
    if ( write_count < n_bytes)
    {
      clearerr (stdout); /* To avoid redundant close_stdout diagnostic.  */
      error (EXIT_FAILURE, errno, "error writing %s", "standard output");
    }
  }                  
}