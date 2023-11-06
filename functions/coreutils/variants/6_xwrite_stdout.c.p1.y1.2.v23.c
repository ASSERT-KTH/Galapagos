1. Alternative using (`do..while` loop) for repetition check:

xwrite_stdout (char const *buffer, size_t n_bytes)
{
  do
  {
    if (n_bytes > 0 && fwrite (buffer, 1, n_bytes, stdout) < n_bytes)
    {
      clearerr (stdout);
      error (EXIT_FAILURE, errno, _("error writing %s"),
          quoteaf ("standard output"));
    }
  } while(0);
}


2. Alternative using (`&&`) operator to execute condition check for short circuit evaluation:

xwrite_stdout (char const *buffer, size_t n_bytes)
{
  n_bytes > 0 && fwrite (buffer, 1, n_bytes, stdout) < n_bytes && (clearerr (stdout), error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output")));
}


3. Alternative using seperate `if` conditions:

xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes > 0) {
      if (fwrite (buffer, 1, n_bytes, stdout) < n_bytes) {
          clearerr (stdout);
          error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
      }
  }
}
  

4. Alternative with `then` clause specific functions:

xwrite_stdout(char const *buffer, size_t n_bytes) {
  if (n_bytes > 0) {
    size_t bytes_written = fwrite(buffer, 1, n_bytes, stdout);
    if (bytes_written < n_bytes) {
      clearerr(stdout);
    }
    if (bytes_written < n_bytes) {
      error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
    }
  }
}
