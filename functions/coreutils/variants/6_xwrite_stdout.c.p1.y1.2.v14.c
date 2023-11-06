1) Enlarging the conditional using an outer guard conditional:

void xwrite_stdout (char const *buffer, size_t n_bytes) {
  if (n_bytes > 0) {
    if (fwrite (buffer, 1, n_bytes, stdout) != n_bytes) {
      clearerr (stdout); 
      error (EXIT_FAILURE, errno, _("error writing %s"),
            quoteaf ("standard output"));
    }
  }
}


2) Using negated conditional:

void xwrite_stdout (char const *buffer, size_t n_bytes) {
  if (!(n_bytes<= 0 || fwrite (buffer, 1, n_bytes, stdout) >= n_bytes)) {
    clearerr (stdout);
    error (EXIT_FAILURE, errno, _("error writing %s"),
        quoteaf ("standard output"));
  }
}


3) Value assignment within condition:

void xwrite_stdout (char const *buffer, size_t n_bytes) {
  ssize_t written_bytes;
  if (n_bytes > 0 && (written_bytes = fwrite (buffer, 1, n_bytes, stdout)) < n_bytes) {
    clearerr (stdout);
    error (EXIT_FAILURE, errno, _("error writing %s"),
          quoteaf ("standard output"));
  }
}
 

4) Using equality comparison rather than inequality in the `fwrite` call:

void xwrite_stdout (char const *buffer, size_t n_bytes) {
  if (n_bytes > 0 && fwrite (buffer, 1, n_bytes, stdout) != n_bytes) {
    clearerr (stdout);
    error (EXIT_FAILURE, errno, _("error writing %s"),
         quoteaf ("standard output"));
  }
}
