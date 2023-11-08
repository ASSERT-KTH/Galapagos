void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t status;
  if (n_bytes > 0){
    status = fwrite (buffer, 1, n_bytes, stdout);
    if(status < n_bytes){
      clearerr (stdout); 
      error (EXIT_FAILURE, errno, _("error writing %s"),
             quoteaf ("standard output"));
    }
  }
}