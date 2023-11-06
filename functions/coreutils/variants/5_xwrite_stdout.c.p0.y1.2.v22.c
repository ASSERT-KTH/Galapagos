void xwrite_stdout (char const *buffer, size_t n_bytes)
{
    size_t written = 0;

    if (n_bytes > 0)
    {
        written = fwrite (buffer, 1, n_bytes, stdout);
            
        if(written < n_bytes)
        {
            clearerr (stdout); /* To avoid redundant close_stdout diagnostic.  */
            error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
        }
      }
}