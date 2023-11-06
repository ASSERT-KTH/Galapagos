wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;
  va_start (args, message);
  
  buflen = vasprintf (&buf, message, args);

  va_end (args);
  
  if (buflen < 0) 
  {
    xalloc_die ();
  }

  if (current_col > 0)
  {
    if ((max_col - current_col) < buflen)
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

  fwrite (buf, sizeof(char), strlen(buf), stdout);
  free (buf);

  current_col = current_col + buflen; 
}