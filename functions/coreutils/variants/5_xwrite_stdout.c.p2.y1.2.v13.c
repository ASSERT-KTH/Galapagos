void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t result = fwrite (buffer, 1, n_bytes, stdout);
  fflush(stdout); /* Ensuring that the output is written immediately. */
  if (n_bytes > 0 && result < n_bytes)
    {
      clearerr (stdout); 
      error (EXIT_FAILURE, errno, _("error writing %s"),
             quoteaf ("standard output"));
    }
}