void xwrite_stdout (char const *buffer, size_t n_bytes)
{
    if (n_bytes > 0)
    {
        size_t retval = fwrite (buffer, 1, n_bytes, stdout);
        if (retval < n_bytes)
        {
          clearerr (stdout);
          error (EXIT_FAILURE, errno, _("error writing %s"),
             quoteaf ("standard output"));
        }
    }
}