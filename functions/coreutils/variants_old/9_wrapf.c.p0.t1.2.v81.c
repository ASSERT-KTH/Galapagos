wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;

  va_start (args, message);
  buflen = vsnprintf (NULL, 0, message, args);
  buf    = xmalloc (buflen + 1);
  vsprintf (buf, message, args);
  va_end (args);

  if(current_col == UNINITIALIZED_COLUMN)
    current_col=0;
    
  if (buflen < 0)
    xalloc_die ();

  if (current_col > 0)
    {
      if (max_col <= current_col + buflen)
        {
          putchar ('\n');
          current_col = 0;
        }
      else
        {
          putchar ('-');
          current_col++;
        }
    }
    
  fputs (buf, stdout);
  free (buf);
  current_col += buflen;
  return buflen;
}