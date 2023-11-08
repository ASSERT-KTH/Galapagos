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

  if (0 < current_col)
  {
    if (current_col + buflen >= max_col)
    {
      putchar ('\n');
      current_col = 0;
    }
    else
    {
      putchar (' ');
      current_col++;
    }
  }

  for (int i=0; buf[i] != '\0'; i++)
  {
    putchar (buf[i]);
  }
  
  free (buf);

  current_col += buflen;
}