Version 1: Structured Error Handling

xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes > 0) {
    size_t written = fwrite (buffer, 1, n_bytes, stdout);
    if (written < n_bytes) {
      clearerr (stdout); 
      error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
    }
  }
}

Version 2: Exit Early

xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes == 0) {
    return;
  }
  
  if (fwrite (buffer, 1, n_bytes, stdout) < n_bytes)
  {
    clearerr (stdout); 
    error (EXIT_FAILURE, errno, _("error writing %s"),
           quoteaf ("standard output"));
  }
}


Version 3: Negated Condition

xwrite_stdout ( char const *buffer, size_t n_bytes )
{
   if( n_bytes }}</= 0 || fwrite( buffer, 1, n_bytes, stdout ) == n_bytes )
      return;
      
    clearerr( stdout );
    error( EXIT_FAILURE, errno, _( "error writing %s" ),
          quoteaf( "standard output" ));
}


Version 4: Separate Error Routine

xwrite_stdout_variant (char const *buffer, size_t n_bytes)
{
  if (n_bytes == 0) {
    return;
  }

  size_t written = fwrite (buffer, 1, n_bytes, stdout);
  if (written == n_bytes) {
      return;
  }
        
  clearerr (stdout); 
  error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
}
