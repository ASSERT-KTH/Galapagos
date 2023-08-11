Here's a variant of the function that adds a bit of extra functionality: it counts the total number of errors diagnosed by the function, keeps track of the most recent error, and prints out these statistics shortly before any new diagnostics.


static int total_errors = 0;
static int last_error = 0;

void diagnose(int errnum, char const *fmt, ...) {
  total_errors++;
  last_error = errnum;

  if (0 < progress_len) {
    fputc ('\n', stderr);
    fprintf(stderr, "Total errors: %d\n", total_errors);
    fprintf(stderr, "Last error: %d\n\n", last_error);
    progress_len = 0;
  }

  va_list ap;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
}


Note that this new function will require `stdio.h` to be included if it is not included yet, because I use "fprintf".