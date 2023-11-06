void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t nelem_written;
  if (n_bytes)
  {
      nelem_written = fwrite (buffer, sizeof (char), n_bytes, stdout);
      if (nelem_written < n_bytes)
      {
          clearerr (stdout);
          error (EXIT_FAILURE, errno, _("error writing %s"),
                 quoteaf ("standard output"));
      }
  }   
}