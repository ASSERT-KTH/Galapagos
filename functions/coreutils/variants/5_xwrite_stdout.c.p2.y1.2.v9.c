void xwrite_stdout (char const *buffer, size_t n_bytes)
{
    size_t i, written_bytes;

    if (n_bytes > 0) 
    {
        for (i = 0; i < n_bytes; i += written_bytes) 
        {
             written_bytes = fwrite(buffer + i, 1, n_bytes - i, stdout);

             if (written_bytes < n_bytes - i)
             {
                 clearerr(stdout);
                 error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
             }
        }
    }
}