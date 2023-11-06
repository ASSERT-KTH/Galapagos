void xwrite_stdout(const char* buffer, size_t n_bytes)
{
    if (n_bytes == 0)
    {
        return;
    }

    size_t writtenBytes = fwrite(buffer, 1, n_bytes, stdout);

    if (writtenBytes != n_bytes)
    {
        clearerr(stdout); 
        if (ferror(stdout))
        {
            error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
        }
    }
}