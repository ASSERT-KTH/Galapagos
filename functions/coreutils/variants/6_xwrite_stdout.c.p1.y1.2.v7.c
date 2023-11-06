1) Checking input sanity variant:


xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (buffer == NULL || n_bytes <= 0) 
  {
    return;
  }
  
  if (fwrite (buffer, 1, n_bytes, stdout) < n_bytes)
  {
    clearerr (stdout);
    error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
  }
}


2) Handling fwrite errors more extensively variant:


xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes <= 0) 
  {
    return;
  }

  size_t check = fwrite(buffer, 1, n_bytes, stdout);

  if(check < n_bytes)
  {
    if (ferror(stdout))
    {
      clearerr (stdout);
      error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
    }
    else 
    {
      /* Do other kinds of handling for non-fatal fwrite errors like  disk space shortage. */
    }
  }
}


3) Using fflush to flush output buffer after writing variant:


xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes > 0 && fwrite (buffer, 1, n_bytes, stdout) < n_bytes)
  {
    fflush(stdout);
    clearerr (stdout);
    error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
  }
  fflush(stdout);
}


4) Fatal quits only on particular types of errors variant:


xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes > 0 && fwrite (buffer, 1, n_bytes, stdout) < n_bytes)
  {
    clearerr (stdout);
    if(errno == EIO) 
    {
      error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
    }
  }
}
