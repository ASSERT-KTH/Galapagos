void wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;

  va_start (args, message);
  buflen = vsnprintf(NULL, 0, message, args);
  
  if (buflen < 0)
    xalloc_die ();
    
  buf = malloc((buflen + 1) * sizeof(char));
  if (buf == NULL)
    xalloc_die ();

  vsnprintf(buf, buflen + 1, message, args);
  va_end (args);

  if (0 < current_col)
    {
      if (max_col - current_col < buflen + 1)
        {
          putc('\n', stdout);
          current_col = 0;
        }
      else
        {
          putc(' ', stdout);
          current_col++;
        }
    }

  size_t wr_len = fwrite (buf, sizeof(char), buflen, stdout);
  free (buf);
  if (wr_len != buflen) 
    xalloc_die ();
  else 
    current_col += buflen;
}