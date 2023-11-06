1. Transforming fwrite and error to their longer form:


void xwrite_stdout(char const *buffer, size_t n_bytes)
{
    if (n_bytes > 0 && fprintf(stdout, "%.*s", (int)n_bytes, buffer) < n_bytes)
    {
        clearerr(stdout);
        perror("error writing standard output");
        exit(EXIT_FAILURE);
    }
}

2. Using putc instead of fwrite:


void xwrite_stdout (char const *buffer, size_t n_bytes) 
{
    size_t i;
    for (i = 0; i < n_bytes; i++) 
    {
        if (putc(buffer[i], stdout) < 0) 
        {
            clearerr (stdout);
            perror("error writing standard output");
            exit(EXIT_FAILURE);
        }
    }
}

3. Checking n_bytes separately:


void xwrite_stdout(char const *buffer, size_t n_bytes) 
{
    if (n_bytes > 0) 
    {
        size_t written = fwrite(buffer, 1, n_bytes, stdout);
        if (written < n_bytes) 
        {
            clearerr(stdout);
            perror("error writing standard output");
            exit(EXIT_FAILURE);
        }
    }
}

4. Using fputc instead putc:


void xwrite_stdout (char const *buffer, size_t n_bytes) 
{
    size_t i;
    for (i = 0; i < n_bytes; i++) 
    {
        if (fputc(buffer[i], stdout) == EOF) 
        {
            clearerr (stdout);
            perror("error writing standard output");
            exit(EXIT_FAILURE);
        }
    }
}
