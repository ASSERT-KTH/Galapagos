Variant 1:

void xwrite_stdout (char const *buffer, size_t n_bytes)
{ 
    size_t result;
    if (n_bytes > 0) {
        result = fwrite (buffer, 1, n_bytes, stdout);
        if (result < n_bytes) {
            clearerr (stdout);
            error (EXIT_FAILURE, errno, _("error writing %s"),
                   quoteaf ("standard output"));
        }
    }
}

Variant 2:

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
    if (!buffer || n_bytes <= 0){
        return;
    }
    if (fwrite (buffer, 1, n_bytes, stdout) < n_bytes) {
        clearerr (stdout); 
        error (EXIT_FAILURE, errno, _("error writing %s"),
               quoteaf ("standard output"));
    }  
}

Variant 3:

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
    if (buffer && n_bytes > 0 && fwrite (buffer, 1, n_bytes, stdout) != n_bytes) {
        clearerr (stdout); 
        error (EXIT_FAILURE, errno, _("error writing %s"),
               quoteaf ("standard output"));
    } 
}

Variant 4:

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
    if (n_bytes > 0 && fwrite(buffer, sizeof(char), n_bytes, stdout) < n_bytes)
    {
        clearerr(stdout);
        error(EXIT_FAILURE, errno, _("error writing %s"),
              quoteaf("standard output"));
    }
}  
