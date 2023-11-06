1. Error Handling Variant - In this variant, the error handling is done in a separate if statement providing more control and code readability.

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t result;
  
  if (n_bytes > 0) {
    result = fwrite (buffer, 1, n_bytes, stdout);
  
    if (result < n_bytes)
    {
      clearerr (stdout); /* To avoid redundant close_stdout diagnostic. */
      error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
    }
  }
}


2. Early Return Variant - This variant provides early return manner of control flow where it reduces code indentation and line length.

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t result;
  
  if (n_bytes == 0) {
    return;
  }
  
  result = fwrite (buffer, 1, n_bytes, stdout);
   
  if (result >= n_bytes){
    return;
  }

  clearerr (stdout); /* To avoid redundant close_stdout diagnostic. */
  error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
}


3. Nested Conditional Statement Variant -This variant provides implementation with nested conditional statements.

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
    if (n_bytes > 0) {
        if (fwrite (buffer, 1, n_bytes, stdout) < n_bytes) {
            clearerr (stdout); /* To avoid redundant close_stdout diagnostic. */
            error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
        }
    } 
}
