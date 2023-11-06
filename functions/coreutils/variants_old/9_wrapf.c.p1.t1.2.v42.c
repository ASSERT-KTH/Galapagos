wrapf (char const *message,...)
{  
  va_list args;
  char *buf;
  int buflen;
  
  va_start (args, message);
  buflen = vsnprintf (NULL, 0, message, args);
  va_end (args);
  
  if ( buflen < 0 )
    abort();

  buf = malloc((size_t ) buflen + 1);

  if ( buf == NULL )
    abort();

  va_start(args, message);
  if (vsnprintf(buf, (size_t ) buflen + 1, message, args) < 0) {
    free(buf);
    abort();
  }
  va_end (args);
  
  if ( 0 < current_col ) 
  {
      if (max_col - current_col <= buflen)
      {
              putc ('\n', stdout);
              current_col = 0;
      }
      else 
      {
              putc(' ', stdout);
              current_col += 1;
      }
  }
  fwrite(buf, sizeof(char), (size_t)buflen, stdout);
  current_col += buflen;

  free (buf);
}