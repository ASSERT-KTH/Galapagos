void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t bytesWritten = 0;
  if (n_bytes > 0)
  {
    bytesWritten = fwrite(buffer, 1, n_bytes, stdout);
    if(n_bytes != bytesWritten) 
    {
      clearerr(stdout); /* To prevent the cluttering of stdout */
      if(errno) 
      {
        error (EXIT_FAILURE, errno, _("error writing %s"),
                    quoteaf ("standard output"));
      }
    }
  }
}