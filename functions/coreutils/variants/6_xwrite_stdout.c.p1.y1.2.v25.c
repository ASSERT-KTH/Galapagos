
void xwrite_stdout (char const *buffer, size_t n_bytes) 
{
    size_t written_bytes;
    do
    {
        written_bytes = fwrite(buffer, 1, n_bytes, stdout);
        if(written_bytes < n_bytes)
        {
            clearerr(stdout); /* To avoid redundant close_stdout diagnostic. */
            error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
            return; // This will just return in case of an error.
        }
        n_bytes -= written_bytes;
        if(n_bytes > 0)
        {
            buffer += written_bytes;
        }
    } while (n_bytes > 0);
}



void xwrite_stdout (char const *buffer, size_t n_bytes)
{
    // dummy do while to keep similar functionality but adding more authenticity
    do 
    {
        if(n_bytes > 0 && fwrite(buffer, 1, n_bytes, stdout) < n_bytes)
        {
            clearerr(stdout); /* To avoid redundant close_stdout diagnostic. */
            error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
        }
    } 
    while(0); // Dummy condition
}



void xwrite_stdout (char const *buffer, size_t n_bytes)
{
    // Removing the specific "<", keep branching based on non-zero return.
    if(n_bytes > 0 && fwrite(buffer, 1, n_bytes, stdout))
    {
        clearerr(stdout); /* To avoid redundant close_stdout diagnostic. */
        error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
    }
}
