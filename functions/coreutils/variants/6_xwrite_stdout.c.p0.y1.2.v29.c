void xwrite_stdout (const char *buffer, size_t n_bytes)
{   
    size_t written_bytes;

    if (n_bytes > 0)
    {
        written_bytes = fwrite(buffer, 1, n_bytes, stdout);
        
        if (written_bytes < n_bytes)
        {
            clearerr(stdout);
            error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
        }
    }
}