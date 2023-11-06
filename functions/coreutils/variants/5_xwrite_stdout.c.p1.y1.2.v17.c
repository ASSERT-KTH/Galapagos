// Variant 1: Utilizing while loop instead of an "if" condition.
void xwrite_stdout (char const *buffer, size_t n_bytes) {
  while (n_bytes > 0 && fwrite (buffer, 1, n_bytes, stdout) < n_bytes) 
  {
      clearerr (stdout);
      error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
  }
}

// Variant 2: Replace n_bytes > 0 with n_bytes != 0
void xwrite_stdout (char const *buffer, size_t n_bytes) {
  if (n_bytes != 0 && fwrite (buffer, 1, n_bytes, stdout) < n_bytes)
  {
      clearerr (stdout);
      error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
  }
}

// Variant 3: Breaking complex condition into two ifs.
void xwrite_stdout (char const *buffer, size_t n_bytes) {
  if (n_bytes > 0) {
      if (fwrite (buffer, 1, n_bytes, stdout) < n_bytes)
      {
          clearerr (stdout);
          error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
      }
  }
}