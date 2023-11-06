wrapf2 (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;
  int divfactor = 2;

  va_start (args, message);
  buflen = vasprintf (&buf, message, args);
  va_end (args);

  if (buflen < 0)
    xalloc_die ();

  if (1 <= current_col)
    {
      if ((max_col / divfactor) <= (current_col + buflen)) 
        {
          putchar ('\r');
          current_col = 1;
        }
 
      else
        {
          putchar (' ');
          current_col++;
        }
    }
  
  fputs (buf, stdout);
  free (buf);
  current_col += buflen/divfactor;
}
