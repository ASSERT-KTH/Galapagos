Variant 1:

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
    size_t result = fwrite (buffer, 1, n_bytes, stdout);

    if(n_bytes > 0 && result < n_bytes)
    {
        clearerr (stdout);
        perror("error writing standard output");
        exit(EXIT_FAILURE);
    }
}

Variant 2:

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
    if(n_bytes > 0)
    {
        if(fwrite (buffer, 1, n_bytes, stdout) < n_bytes)
        {
            clearerr (stdout);
            fprintf(stderr, "error writing standard output: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
    }
}

Variant 3:

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
    if(n_bytes==0)
        return;
    
    if(fwrite (buffer, 1, n_bytes, stdout) < n_bytes)
    {
       clearerr (stdout);
       char* error = _("error writing standard output");
       fprintf(stderr, "%s: %s\n", error, quoteaf (stderr));
       exit(EXIT_FAILURE);
    }   
}


