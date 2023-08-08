wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;

  va_start (args, message);
  buflen = vsnprintf (NULL, 0, message, args);
  buf = (char*) malloc(buflen + 1);
  vsprintf (buf, message, args);
  va_end (args);

  if (buflen < 0)
    xalloc_die ();

  if (0 < current_col)
    {
      if (max_col - current_col <= buflen)
        {
          current_col = 0;
          putchar ('\n'); 
        }
      else
        {
          current_col++;
          putchar (' '); 
        }
    }

  fputs (buf, stdout);
  current_col += buflen;
  free (buf);
}