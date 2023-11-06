1. This variant carries the checking for empty bytes right up to header.

xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes <= 0) return;

  if (fwrite (buffer, 1, n_bytes, stdout) < n_bytes)
    {
      clearerr (stdout);
      error (EXIT_FAILURE, errno, _("error writing %s"),
             quoteaf ("standard output"));
    }
}


2. This variant manually loops to write each byte. This deals with intermittent failures where fwrite fails to write all bytes.


xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes > 0) {
     for(size_t i = 0; i < n_bytes; i++) 
     {
        clearerr(stdout);
        if(EOF == putc(buffer[i], stdout)) 
        {
            error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
            break;
        }
     }
  }
}


3. Pointer arithmetic is more tricky but it's inline with C semantics. 


xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes > 0){
    char const *end_buffer = buffer + n_bytes;
    while(buffer < end_buffer){
        clearerr(stdout);
        if(EOF == putc(*buffer++, stdout)){
            error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
            break;
        }
    }
  }
}
    

4. This comes at this from a redundancy standpoint. We reset the error immediately before writing.


xwrite_stdout (char const *buffer, size_t n_bytes)
{
  clearerr (stdout); 
  if (n_bytes > 0 && fwrite (buffer, 1, n_bytes, stdout) < n_bytes)
    {
      error (EXIT_FAILURE, errno, _("error writing %s"),
             quoteaf ("standard output"));
      clearerr (stdout);
    }
}
