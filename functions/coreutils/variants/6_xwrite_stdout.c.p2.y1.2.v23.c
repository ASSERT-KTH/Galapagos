char const *xwrite_stdout (char const *buffer, size_t n_bytes)
{
  int result;
  if (n_bytes != 0)
  {
      if((result = fwrite (buffer, 1, n_bytes, stdout)) == n_bytes)
          return buffer;
      else if (result < n_bytes && ferror(stdout))
      {
          clearerr (stdout);
          error (EXIT_FAILURE, errno, "error writing %s", quoteaf ("standard output"));
      }
  }
  
  return buffer;
}