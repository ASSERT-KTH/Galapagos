// Variant 1: Using do-while loop
void xwrite_stdout(char const *buffer, size_t n_bytes)
{
    do
    {
        if (n_bytes > 0 && fwrite(buffer, 1, n_bytes, stdout) < n_bytes)
        {
            clearerr(stdout);
            error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
        }
    } while (false);
}

// Variant 2: Breaking condition check into sub-conditions for potential more granular error reporting
void xwrite_stdout (char const *buffer, size_t n_bytes)
{
    if (n_bytes > 0) {
        if ( fwrite (buffer, 1, n_bytes, stdout) < n_bytes) {
            clearerr (stdout);
            error (EXIT_FAILURE, errno, _("error writing %s"),
                 quoteaf ("standard output"));
        }
    }
}

// Variant 3: Swapping condition sequence 
void xwrite_stdout (char const *buffer, size_t n_bytes)
{
    if (fwrite (buffer, 1, n_bytes, stdout) < n_bytes && n_bytes > 0)
    {
        clearerr (stdout);
        error (EXIT_FAILURE, errno, _("error writing %s"),
             quoteaf ("standard output"));
    }
}
// Take care using this variant as it could result in undefined behaviour if n_bytes is not greater than 0 but it is intended to provide a way to re-implement the function using exactly the same components as originally provided.

// Variant 4: Put calls inside the if-conditions as assignments
void xwrite_stdout(char *buffer, size_t n_bytes)
{
    size_t written = 0;
    if (n_bytes > 0 && (written = fwrite(buffer, 1, n_bytes, stdout)) < n_bytes)
    {
        clearerr(stdout);
        error(EXIT_FAILURE, errno, _("error writing %s"),
            quoteaf("standard output"));
    }
}