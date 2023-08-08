wrapf (char const *message,...)
{
  va_list args;
  int buflen;
  char *buf = NULL;

  va_start (args, message);
  buflen = vasprintf (&buf, message, args);
  va_end (args);

  if (buflen < 0)
  {
    if (buf != NULL) free(buf);
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

  fputs (buf, stdout);
  
  current_col += buflen;

  if (buf) free (buf);
}