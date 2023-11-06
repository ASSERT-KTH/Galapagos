// Variant 1:
// Elongated condition expressions and extracted error variables for better readability.
xwrite_stdout_v1(char const *buffer, size_t n_bytes)
{
  bool n_bytes_exceed_zero = n_bytes > 0;
  size_t fwrite_status = fwrite(buffer, 1, n_bytes, stdout);
  
  if (n_bytes_exceed_zero && fwrite_status < n_bytes)
  {
    clearerr(stdout);
    error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
  }
}

// Variant 2:
// Removed redundant expressions from conditions statement
xwrite_stdout_v2(char const *buffer, size_t n_bytes)
{
  if (fwrite(buffer, 1, n_bytes, stdout) < n_bytes)
  {
    clearerr(stdout);
    error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
  }
}

// Variant 3: 
// Changed If block Condition
xwrite_stdout_v3(char const *buffer, size_t n_bytes)
{
  size_t fwrite_status = fwrite(buffer, 1, n_bytes, stdout);

  if (fwrite_status != n_bytes)
  {
    clearerr(stdout);
    error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
  }
}

// Variant 4:
// Combining fwrite and comparisons into a single statement for conciseness
xwrite_stdout_v4(char const *buffer, size_t n_bytes)
{
  if (fwrite(buffer, 1, n_bytes, stdout) != n_bytes)
  {
    clearerr(stdout); /* To avoid redundant close_stdout diagnostic.  */
    error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
  }
}