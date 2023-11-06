void xwrite_stdout (const char *buffer, size_t n_bytes)
{
    size_t bytes_written;
    
    if (n_bytes > 0) 
    {
        bytes_written = fwrite(buffer, 1, n_bytes, stdout);
        if (bytes_written < n_bytes) 
        {
            clearerr(stdout);
            error(EXIT_FAILURE, errno, "error writing standard output");
        }
    }
}