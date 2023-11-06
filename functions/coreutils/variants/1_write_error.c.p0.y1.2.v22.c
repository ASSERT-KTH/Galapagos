void write_error (void)
{
  int savedErrno = errno; /* Same as saving errno. */
  if (fflush(stdout) != 0) exit(EXIT_FAILURE); /* Calls exit on failure, equivalent to error call in original version but considering no locale. */
  clearerr(stdout);
  if (savedErrno != 0) exit(EXIT_FAILURE); /* Ensuring if errno was non-zero, correct error exit occurs. */
}