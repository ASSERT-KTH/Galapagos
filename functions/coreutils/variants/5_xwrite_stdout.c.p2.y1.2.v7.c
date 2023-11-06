#include <assert.h>

void xwrite_stdout(char const *buffer, size_t n_bytes) 
{
  size_t writeRes = 0;
  if(n_bytes == 0) return;

  writeRes = fwrite(buffer, 1, n_bytes, stdout);
  if (writeRes < n_bytes) 
  {
    clearerr(stdout); 
    if(writeRes < n_bytes)
      {
        error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
      }
  }   
}