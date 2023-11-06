1. Checking the fwrite result separately:

void xwrite_stdout(char const *buffer, size_t n_bytes)
{   
    if (buffer != NULL && n_bytes > 0) 
    {
        size_t written = fwrite(buffer, 1, n_bytes, stdout);
        if (written < n_bytes)
        {
            clearerr(stdout);
            error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
        }
    }
}

2. Inverting the condition check:

void xwrite_stdout(char const *buffer, size_t n_bytes)
{   
    if (!(n_bytes > 0))
        return;

    if (fwrite (buffer, 1, n_bytes, stdout)< n_bytes)
    {
        clearerr(stdout);
        error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
    }
}

3. Using early return for null buffer:

void xwrite_stdout(char const *buffer, size_t n_bytes)
{   
    if (buffer == NULL || n_bytes == 0)
        return;

    size_t written = fwrite(buffer, 1, n_bytes, stdout);
    if (written < n_bytes)
    {
        clearerr(stdout);
        error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
    }
}

4. Using else case for the function error condition:

void xwrite_stdout(char const *buffer, size_t n_bytes)
{   
    if (n_bytes == 0)
        return;

    if (fwrite (buffer, 1, n_bytes, stdout) >= n_bytes)
        return;
    else 
    {
        clearerr(stdout);
        error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
    }
}
