1. Using do-while loop: 

void xwrite_stdout(char const *buffer, size_t n_bytes)
{
    do
    {
        if (n_bytes == 0 || fwrite(buffer, 1, n_bytes, stdout) >= n_bytes)
            return;
        
        clearerr(stdout);
        error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
    }
    while (false);
}


2. Using guard clause:

void xwrite_stdout(char const *buffer, size_t n_bytes)
{
    if (n_bytes != 0 && fwrite(buffer, 1, n_bytes, stdout) >= n_bytes) 
        return;

    clearerr(stdout);
    error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
}


3. Changing the conditional structure:

void xwrite_stdout(char const *buffer, size_t n_bytes)
{
    if(n_bytes == 0)
        return;

    if(fwrite(buffer, 1, n_bytes, stdout) < n_bytes)
    {
        clearerr(stdout);
        error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
    }
}
  

4. Removing Magic number and rearranging conditions:
 
void xwrite_stdout(char const *buffer, size_t n_bytes)
{
    const size_t SUCCESS_BYTEWRITE_VALUE = 1;

    if(n_bytes <= 0)
        return;

    if(fwrite(buffer, SUCCESS_BYTEWRITE_VALUE, n_bytes, stdout) != n_bytes)
    {
        clearerr(stdout);
        error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
    }
}
