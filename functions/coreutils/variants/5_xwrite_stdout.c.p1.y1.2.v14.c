1) Removed the clearerr function call. It is usually not necessary to call "clearerr" to clear error or EOF from the stream, as error handling is built-in when error( ) is called.

void xwrite_stdout (char const *buffer, size_t n_bytes) {
    if (n_bytes > 0 && fwrite(buffer, 1, n_bytes, stdout) < n_bytes) {
        error(EXIT_FAILURE, errno, _("error writing %s"), 
        quoteaf("standard output"));
    }
}


2) Intermediate variable in-place for clarity:

void xwrite_stdout (char const * buffer, size_t n_bytes) {
    size_t written = fwrite(buffer, 1, n_bytes, stdout);
    if (n_bytes > 0 && written < n_bytes) {
        clearerr(stdout);
        error(EXIT_FAILURE, errno, _("error writing %s"), 
        quoteaf("standard output"));
    }
}


3) Moved the "n_bytes > 0" to outcria check for efficiency and less confusing control flow

void xwrite_stdout (char const *buffer, size_t n_bytes) {
    if (n_bytes == 0) {
        return;
    }
      
    if (fwrite(buffer, 1, n_bytes, stdout) < n_bytes) {
        clearerr (stdout);
        error(EXIT_FAILURE, errno, _("error writing %s"),
        quoteaf ("standard output"));
    }
}


4) Change the order of the arguments in fwrite for a clarity

void xwrite_stdout (char const *buffer, size_t n_bytes) {
    if (n_bytes > 0 && fwrite(buffer, n_bytes, 1, stdout) < 1) {
        clearerr (stdout);
        error(EXIT_FAILURE, errno, _("error writing %s"),
        quoteaf ("standard output"));
    }
}
