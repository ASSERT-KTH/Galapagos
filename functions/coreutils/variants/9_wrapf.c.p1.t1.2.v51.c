wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;

  va_start (args, message);
  buflen = vasprintf (&buf, message, args);
  va_end (args);

  if (buflen <=0 )
    {
      xalloc_die ();
    }
  else 
  {
    if (current_col > 0)
    {
      if (max_col - current_col > buflen)
      {
        putchar (' ');
        current_col++;
      }
      else
      {
        putchar ('\n');
        current_col = 0;
      }
    }

    fputs (buf, stdout);
    current_col += buflen;
    free (buf);
  }
}
