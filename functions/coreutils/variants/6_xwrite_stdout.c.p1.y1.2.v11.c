1. Alternative using errno:


xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes == 0) return;
  if (fwrite(buffer, 1, n_bytes, stdout) < n_bytes) {
    int write_error = errno;
    clearerr(stdout);
    if (write_error != 0) {
      errno = write_error;
      error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
    }
  }
}
 

2. Alternative using fflush:


xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes > 0) {
    if (fwrite(buffer, 1, n_bytes, stdout) < n_bytes || fflush(stdout) != 0) {
      int errNum = errno;
      clearerr(stdout);
      error(EXIT_FAILURE, errNum, _("error writing %s"), quoteaf("standard output"));
    }
  }
}


3. Alternative using fseek:


xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes > 0 ) {
    if (fwrite(buffer, 1, n_bytes, stdout) != n_bytes) {
      fseek(stdout, 0L, SEEK_CUR);
      error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
    } else if (ferror(stdout)) {
      clearerr(stdout);
      error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
    }
  }
}


4. Alternative using putc:


xwrite_stdout (char const *buffer, size_t n_bytes)
{
  const char *end = buffer + n_bytes;
  for (const char *p = buffer; p != end; ++p) {
    if (putc(*p, stdout) == EOF) {
      clearerr(stdout);
      error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
      break;
    }
  }
}


The above four different implementations have the same function signature and fulfill all the primary functionalities of the original function. They respectively base on different functions or methods to output string to stdout and conducts error checking accordingly.