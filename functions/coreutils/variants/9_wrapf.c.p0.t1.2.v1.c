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

  int remaining_cols = max_col - current_col;
  if (current_col > 0)
  {
    if (remaining_cols <= buflen)
    {
      putchar ('\n');
      current_col = 0;
    }
    else
    {
      putchar ('\t');
      current_col++;
    }
  }

  fputs (buf, stdout);
  free (buf);
  current_col += buflen;

  if (current_col > max_col)
  {
    putchar('\n');
    current_col = 0;
  }  
}