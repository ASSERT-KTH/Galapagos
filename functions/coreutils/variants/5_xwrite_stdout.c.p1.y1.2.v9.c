1. Checking fwrite's return result separately from initial conditional:

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes > 0)
  {
    size_t result = fwrite(buffer, 1, n_bytes, stdout);
    if (result < n_bytes)
    {
      clearerr(stdout);
      error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
    }
  }
}


2. Changing error string format:

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes > 0 && fwrite(buffer, 1, n_bytes, stdout) < n_bytes)
  {
    clearerr(stdout);
    error(EXIT_FAILURE, errno, _("error writing to %s"), "standard output");
  }
}


3. Inverting initial conditional:

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (!(n_bytes <= 0 || fwrite(buffer, 1, n_bytes, stdout) >= n_bytes))
  {
    clearerr(stdout);
    error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
  }
}


4. Calling clearerr() before fwrite:

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes > 0)
  {
    clearerr(stdout);
    if (fwrite(buffer, 1, n_bytes, stdout) < n_bytes)
    {
      error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
    }
  }
}


5. Setting fwrite inside a variable within the initial conditional:

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t res;

  if(n_bytes > 0 && (res = fwrite (buffer, 1, n_bytes, stdout)) < n_bytes)
  {
    clearerr(stdout);
    error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
  }
}
