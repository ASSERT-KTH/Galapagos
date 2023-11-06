void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t written = 0;

  while ((written < n_bytes) && !ferror(stdout)) {
    written += fwrite (buffer + written, 1, n_bytes - written, stdout);
  }
  
  if (ferror(stdout)) 
  {
    clearerr (stdout);
    error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
  }
}