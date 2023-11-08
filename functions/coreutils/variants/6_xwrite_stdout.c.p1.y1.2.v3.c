1)

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
    size_t write_res;
    
    if (!((n_bytes == 0) || 
          ((write_res = fwrite (buffer, 1, n_bytes, stdout)) >= n_bytes))) 
    {
        clearerr (stdout); 
        error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
    }
}

  
2)

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
    if (n_bytes == 0) return;
    
    if (fwrite(buffer, 1, n_bytes, stdout) != n_bytes)
    {
        clearerr(stdout);
        error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
    }
}


3)

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
    if (!(n_bytes == 0))
    {
        if (fwrite (buffer, 1, n_bytes, stdout) < n_bytes)
        {
            clearerr (stdout); 
            error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
        }
    }
}


4)

void xwrite_stdout(char const *buffer, size_t n_bytes)
{
    size_t w_res = (n_bytes) ? fwrite(buffer, 1, n_bytes, stdout) : n_bytes;

    if(w_res < n_bytes)
    {
        clearerr(stdout);
        error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
    }
}  