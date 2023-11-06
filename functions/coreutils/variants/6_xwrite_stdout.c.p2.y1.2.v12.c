void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes == 0) 
  {
     return;
  }

  size_t write_result = fwrite(buffer, 1, n_bytes, stdout);
  if (write_result < n_bytes) 
  {
      int myErrno = errno;
      clearerr (stdout); /* To avoid redundant close_stdout diagnostic.  */
      error (EXIT_FAILURE, myErrno, _("error writing %s"), quoteaf ("standard output"));
  }
}