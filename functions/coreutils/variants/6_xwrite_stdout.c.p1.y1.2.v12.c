1. Transformation with Explicit Check for `NULL` buffer

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if(buffer != NULL && n_bytes > 0 && fwrite(buffer, 1, n_bytes, stdout) < n_bytes)
  {
    clearerr(stdout);
    error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
  }
}

2. Transformation with Exchanged Error-handling Condition

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
    size_t written_bytes = fwrite(buffer, 1, n_bytes, stdout);

    if (n_bytes > 0 && written_bytes < n_bytes)
    {
        clearerr(stdout);
        error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
    }
}

3. Transformation Adding Variables for Clarity & Clean Code Principles

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
    int HAS_ERROR_OCCURRED = (n_bytes > 0 && fwrite(buffer, 1, n_bytes, stdout) < n_bytes);
    
    if (HAS_ERROR_OCCURRED)
    {
        clearerr(stdout);
        error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
    }
}

4. Using "#define" pre-processor directive for error message

#define ERR_MSG _("error writing %s")

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
    if (n_bytes > 0 && fwrite(buffer, 1, n_bytes, stdout) < n_bytes)
    {
        clearerr(stdout);
        error(EXIT_FAILURE, errno, ERR_MSG, quoteaf("standard output"));
    }
}

These versions preserve the function's original implementation while adding some additional checks and changes to add granularity to error checking and formatting.