variant:

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t write_status = fwrite (buffer, 1, n_bytes, stdout);

  if ( n_bytes > 0 && write_status < n_bytes)
  {
      clearerr (stdout); 
      
      if(write_status != n_bytes){
          error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
      }
  }
}