Variant 1:

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
    if (n_bytes > 0)
    {  
        size_t result = fwrite (buffer, 1, n_bytes, stdout);
        if(result < n_bytes)
        {
            clearerr (stdout);
            error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
        }
    }
}


Variant 2:

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
    if (n_bytes > 0) 
    {
        size_t written_bytes = fwrite (buffer, 1, n_bytes, stdout);

        if(written_bytes != n_bytes)
        {
            clearerr (stdout);
            error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
        }
    }
}


Variant 3:

void xwrite_stdout (char const *buffer, size_t n_bytes)
{ 
    size_t result;
    if (n_bytes) 
    {
        result = fwrite(buffer, 1, n_bytes, stdout);
    }

    if(result < n_bytes && n_bytes > 0)
    {
        clearerr (stdout);
        error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
    }
}


Variant 4:

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
    if (n_bytes) 
    {
      size_t result = fwrite (buffer, 1, n_bytes, stdout);
      if(result != n_bytes)
      {
          clearerr (stdout);
          error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));	
      }
    }
}
