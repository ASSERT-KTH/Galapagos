1. Transformation with explicit return to emphasize execution result:

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes > 0) {
    if (fwrite (buffer, 1, n_bytes, stdout) < n_bytes) {
      clearerr (stdout); /* To avoid redundant close_stdout diagnostic.  */
      error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
      return;
    }
  }
  return;
}


2. Transformation with separation of error and validation conditions:

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if(n_bytes <= 0)
    return;
  
  if(fwrite (buffer, 1, n_bytes, stdout) < n_bytes)
    {
      clearerr (stdout); /* To avoid redundant close_stdout diagnostic.  */
      error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
    }
}


3. Transformation with use of ternary operator

  void xwrite_stdout (char const *buffer, size_t n_bytes)
  {
    (n_bytes > 0 && fwrite (buffer, 1, n_bytes, stdout) < n_bytes) ? 
    (void)(clearerr (stdout), /* To avoid redundant close_stdout diagnostic. */
     error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"))) 
    : (void)0;
  }


4. Function throws error on failure simplified,

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
    if (fwrite(buffer, 1, n_bytes, stdout) != n_bytes)
    {
        clearerr(stdout); //to avoid redundant close_stdout diagnostic
        error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
    }
}

Please note that these transformations indeed provide the same functionality to the given code function in different ways, they do change behavioral pattern of the original function where error would be executed when the were no bytes to be written e.g. when `n_bytes` equaled 0. Now, in most of the transformed versions if `n_bytes` equals to 0 it just returns without throwing an error. Consider adding a more specific error message if n_bytes==0, just depending on how you want to handle that case.