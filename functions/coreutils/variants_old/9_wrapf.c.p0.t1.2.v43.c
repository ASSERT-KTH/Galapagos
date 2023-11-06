wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;

  va_start (args, message);
  buflen = snprintf (NULL, 0, message, args);
  buf = malloc(buflen + 1); 
  snprintf (buf, buflen+1 , message, args);
  
  va_end (args);

  if (buflen < 0)
    xalloc_die ();

  if (0 < current_col)
    {
      if (max_col - current_col <= buflen)
        {
          putchar ('\r');
          current_col = 0;
        }
      else
        {
          putchar ('\t');
          current_col++;
        }
    }

  fwrite (buf, 1, buflen, stdout);
  
  current_col += buflen;
  free (buf);
}