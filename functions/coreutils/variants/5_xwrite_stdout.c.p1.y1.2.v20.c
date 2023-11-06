Variant 1: Removes redundant close_stdout diagnostic using else statement instead of the clearerr function

void xwrite_stdout (char const *buffer, size_t n_bytes) {
  size_t write_size; 
  if (n_bytes > 0) {
    write_size = fwrite (buffer, 1, n_bytes, stdout);
    if(write_size < n_bytes) {
        error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
    }
  }
}

Variant 2: Using do-while loop instead of if condition

void xwrite_stdout (char const *buffer, size_t n_bytes) {
  do {
    if (n_bytes <= 0 || fwrite (buffer, 1, n_bytes, stdout) >= n_bytes)
        break;
    clearerr (stdout);
    error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
  } while(0);
}


Variant 3: Error handling happens before return inside if condition

void xwrite_stdout (char const *buffer, size_t n_bytes) {
    if (n_bytes <= 0)
        return;
    if (fwrite(buffer, 1, n_bytes, stdout) >= n_bytes)
        return;

    clearerr (stdout);
    error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
}


Variant 4: Function call inside condition after bitwise and operator

void xwrite_stdout (char const *buffer, size_t n_bytes) {
    if (n_bytes && fwrite(buffer, 1, n_bytes, stdout) < n_bytes) {
        clearerr (stdout);
        error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
    }
}
