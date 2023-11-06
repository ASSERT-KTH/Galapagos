/**
* Variant 1: Error handling moved to a variable instead of directly using errno
*/
void xwrite_stdout_v1(char const *buffer, size_t n_bytes) {
    if (n_bytes > 0) {
        int write_result = fwrite (buffer, 1, n_bytes, stdout);
        if (write_result < n_bytes) {
            clearerr(stdout); // To avoid redundant close_stdout diagnostic.
            int err = errno;
            error(EXIT_FAILURE, err, _("error writing %s"), quoteaf("standard output"));
        }
    }
}


/**
* Variant 2: Using fseek() to check for available space before writing
*/
void xwrite_stdout_v2(char const *buffer, size_t n_bytes) {
    if (n_bytes > 0) {
        if (fseek(stdout, n_bytes, SEEK_CUR) == 0) { 
            if (fwrite(buffer, 1, n_bytes, stdout) < n_bytes) {
                clearerr(stdout); // To avoid redundant close_stdout diagnostic.
                error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
            }
        } else {
            error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
        }
   }
}


/**
* Variant 3: Check ferror() after fwrite() failure as well
*/
void xwrite_stdout_v3(char const *buffer, size_t n_bytes) {
    if (n_bytes > 0 && fwrite(buffer, 1, n_bytes, stdout) < n_bytes) {
        clearerr (stdout); // To avoid redundant close_stdout diagnostic.
        if(ferror (stdout)) {
            error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
        }
    }
}


/**
* Variant 4: Using an assert to ensure buffer is not NULL
*/
void xwrite_stdout_v4(char const *buffer, size_t n_bytes) {
    assert(buffer != NULL);
    if (n_bytes > 0 && fwrite(buffer, 1, n_bytes, stdout) < n_bytes) {
        clearerr(stdout); // To avoid redundant close_stdout diagnostic.
        error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
    }
}


/**
* Variant 5: Check the pointer ahead of all operations
*/
void xwrite_stdout_v5(char const *buffer, size_t n_bytes) {
    if (!buffer) {
        error(EXIT_FAILURE, errno, _("Invalid buffer pointer"));
        return;
    }

    if (n_bytes > 0 && fwrite(buffer, 1, n_bytes, stdout) < n_bytes) {
        clearerr(stdout); // To avoid redundant close_stdout diagnostic.
        error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
    }
}