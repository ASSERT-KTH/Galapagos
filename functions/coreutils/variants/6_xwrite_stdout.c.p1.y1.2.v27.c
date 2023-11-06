1. Error Handling
This version handles the case where `fwrite()` fails to write all the bytes defined by `n_bytes`. It retries until all the bytes are written.


xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t total_written = 0;

  if (n_bytes > 0)
    {
      while(total_written < n_bytes)
        {
          size_t written = fwrite (buffer + total_written, 1, 
                                   n_bytes - total_written, stdout);
                                   
          if(written)
            total_written += written;
          else
            {
              clearerr (stdout); 

              error (EXIT_FAILURE, errno, _("error writing %s"),
                     quoteaf ("standard output"));
              break;
            }
        }
    }
}


2. Checking fwrite() for EOF
This version checks if `fwrite()` returns `EOF`, which indicates an error occurred.


xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes > 0)
    {
      if (fwrite (buffer, 1, n_bytes, stdout) != n_bytes)
        {
          if (feof(stdout))
            {
              clearerr (stdout);

              error (EXIT_FAILURE, errno, _("error writing %s (End of File detected)"),
                     quoteaf ("standard output"));
            }
          else 
            {
              error (EXIT_FAILURE, errno, _("error writing %s"),
                     quoteaf ("standard output"));
            }
        }

      if (ferror(stdout))
        {
          clearerr (stdout); 

          error (EXIT_FAILURE, errno, _("Previous fwrite() error did not set EOF flag"),
                quoteaf ("standard output"));
        }
    }
}


3. Error Logging
This version implements logs error messages within the function. After writing, it checks if an error occurred during operation of fwrite.


xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes > 0)
    {
      if (fwrite (buffer, 1, n_bytes, stdout) < n_bytes)
        {
          if (ferror(stdout))
            {
              clearerr (stdout);
              
              fprintf(stderr, "Failed to write the buffer to standard output\n");
              
              error (EXIT_FAILURE, errno, _("error writing %s"),
                     quoteaf ("standard output"));
            }
        }
    }
}
