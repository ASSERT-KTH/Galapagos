1. Uncommented version


xwrite_stdout (char const *buffer, size_t n_bytes) {
   if (n_bytes > 0 && fwrite (buffer, 1, n_bytes, stdout) < n_bytes) {
       clearerr (stdout);
       error (EXIT_FAILURE, errno, "error writing %s", quoteaf ("standard output"));
   }
}


2. Refactored version without using clearerr function 


xwrite_stdout (char const *buffer, size_t n_bytes) 
{
  size_t write_count = 0;
  if (n_bytes > 0) 
  {
    write_count = fwrite(buffer, 1, n_bytes, stdout);
    if(write_count < n_bytes)
    { 
      error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
    }
  }
}


3. Expressively checking fwrite function


xwrite_stdout (char const *buffer, size_t n_bytes) {
   size_t result;
   if (n_bytes > 0) {
      result = fwrite (buffer, 1, n_bytes, stdout);
      if (result < n_bytes) {
         clearerr (stdout);
         error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
      }
   }
}


4. Returning result instead of using error function 


int xwrite_stdout (char const *buffer, size_t n_bytes) {
  if (n_bytes > 0 && fwrite (buffer, 1, n_bytes, stdout) < n_bytes)  
  {
    clearerr (stdout);
    return errno; 
  }
  return 0;
}
 

5. Using perror to print error message instead of printf 


xwrite_stdout (char const *buffer, size_t n_bytes) {
  if (n_bytes > 0 && fwrite (buffer, 1, n_bytes, stdout) < n_bytes) 
  {
    clearerr (stdout);
    perror(quoteaf ("standard output"));
    exit(EXIT_FAILURE);
  }
}
