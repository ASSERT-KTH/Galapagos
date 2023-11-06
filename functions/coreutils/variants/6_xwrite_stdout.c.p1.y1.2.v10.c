1.

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t res = 0;
  if (n_bytes > 0)
  {
    res = fwrite(buffer, 1, n_bytes, stdout);
    if (res < n_bytes)
    {
      clearerr(stdout);
      error(EXIT_FAILURE, errno,
            "error writing %s",
            "standard output");
    }
  }
}


2.

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes == 0) 
  {
    return;
  }

  size_t written_bytes = fwrite (buffer, 1, n_bytes, stdout);

  if (written_bytes < n_bytes) 
  {
    clearerr (stdout); 
    error (EXIT_FAILURE, errno,
           "error writing %s",
           "standard output");
  }
}


3.

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if(n_bytes > 0)
  {
    size_t res = fwrite (buffer, 1, n_bytes, stdout);
    if (res == n_bytes)
    {
      return;
    }

    clearerr(stdout);
    error(EXIT_FAILURE, errno,
          "error writing %s",
          "standard output");
  } 
}
    

4.

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if(n_bytes <= 0 || fwrite (buffer, 1, n_bytes, stdout) >= n_bytes)
  { 
    return;
  }
  
  clearerr (stdout);
  error (EXIT_FAILURE, errno,
         "error writing %s",
         "standard output");
}
    
5.

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes == 0) return;

  if (fwrite(buffer, 1, n_bytes, stdout) == n_bytes) return;

  clearerr (stdout);
  error(EXIT_FAILURE, errno,
        "error writing %s",
        "standard output");
}
