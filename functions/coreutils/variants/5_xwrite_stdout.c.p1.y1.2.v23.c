1. Another variant with changed order of validation could be:

void xwrite_stdout(char const *buffer, size_t n_bytes) {
    if (fwrite(buffer, 1, n_bytes, stdout) < n_bytes && n_bytes > 0) {
        clearerr(stdout); 
        error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
    }
}

2. Checking fwrite only if n_bytes > 0

void xwrite_stdout(char const *buffer, size_t n_bytes) {
    if (n_bytes <= 0) return;

    if (fwrite(buffer, 1, n_bytes, stdout) < n_bytes) {
        clearerr(stdout); 
        error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
    } 
}

3. Overhead in fwrite explicitly handled (instead they're implicit)

void xwrite_stdout(char const *buffer, size_t n_bytes) {
    if (n_bytes > 0) {
        size_t written_bytes = fwrite(buffer, 1, n_bytes, stdout);
        if (written_bytes < n_bytes) {
            clearerr(stdout); 
            error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
        }
    }
}

4. Early exiting in case of 0 bytes to write

void xwrite_stdout(char const *buffer, size_t n_bytes) {
    if (n_bytes == 0)
        return;

    if (fwrite(buffer, 1, n_bytes, stdout) < n_bytes) {
        clearerr(stdout);
        error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
    }
}
