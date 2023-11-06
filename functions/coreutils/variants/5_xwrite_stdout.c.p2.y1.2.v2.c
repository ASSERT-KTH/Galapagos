void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t ret_val;
  
  if (n_bytes != 0)
  {
    ret_val = fwrite(buffer, 1, n_bytes, stdout);
    
    if (ret_val < n_bytes)
    {
      int fwrite_errno = errno;
      
      clearerr (stdout);
      
      error (EXIT_FAILURE, fwrite_errno, _("error writing %s"),
             quoteaf ("standard output"));
    }
    
  }
}