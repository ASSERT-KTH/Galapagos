Variant 1:

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t bytes_written;
  
  bytes_written = fwrite (buffer, 1, n_bytes, stdout);

  if (n_bytes > 0 && bytes_written < n_bytes) 
    {
      clearerr (stdout);
      error (EXIT_FAILURE, errno, _("error writing %s"),
             quoteaf ("standard output"));
    }
}


Variant 2:

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (!n_bytes)  
    return;
    
  if (fwrite(buffer, 1, n_bytes, stdout) != n_bytes) 
    {
      clearerr (stdout);
      error (EXIT_FAILURE, errno, _("error writing %s"),
             quoteaf ("standard output"));
    }
}


Variant 3:

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes && fwrite (buffer, 1, n_bytes, stdout) < n_bytes) 
    {
      clearerr (stdout);
      error (EXIT_FAILURE, errno, _("error writing %s"),
             quoteaf ("standard output"));
    }
}


Variant 4:

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
   int n_written;
   
   if (n_bytes) 
   {
       n_written = fwrite(buffer, 1, n_bytes, stdout);
       
       if (n_written < n_bytes) 
       {
           clearerr (stdout);
           error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
       }
   }
}
