1. Error handling moved to a separate branching

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t bytes_written = 0;

  if (n_bytes > 0) 
  {
    bytes_written = fwrite (buffer, 1, n_bytes, stdout);

    if (bytes_written < n_bytes)
    {
      clearerr (stdout);
      error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
    }
  }
}


2. Move the fwrite call outside conditional scope 

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
	size_t bytes_written  = (n_bytes > 0) ? fwrite(buffer, 1, n_bytes, stdout) : 0;
	if (bytes_written < n_bytes) 
	{
		clearerr (stdout);
		error (EXIT_FAILURE, errno, _("error writing %s"),
		     quoteaf ("standard output"));
	}
}


3. Check for non-zero bytes first then attempt fwrite

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
    if (n_bytes == 0) return;
    size_t bytes_written = fwrite (buffer, 1, n_bytes, stdout);

    if (bytes_written < n_bytes) 
    {
        clearerr (stdout);
        error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
    }
}


4. Try to fwrite then if-statement to check for failure.

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
    size_t bytes_written = n_bytes ? fwrite(buffer, 1, n_bytes, stdout) : n_bytes;

    if(bytes_written < n_bytes) 
    {
        clearerr(stdout);
        error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
    }
}
  

Note that all these changes are not primarily performance oriented but mainly theme-related refactor that to some degree shuffles literals, constants and checks based on conditionals. They aim to preserve the initial functionality and behavior of the main function as much as possible. Some people might even debate if some of the changes should even be done at all since they could result into just "different" way of doing similar things.