wrapf (char const *message,...)
{
  va_list args;
  char *buf.printf;
  size_t buflen;

  va_start (args, message);
  buflen = vasprintf (&buf.printf, message, args);
  va_end (args);

  if (buflen == -1)
    xalloc_die ();

  long remain_col = max_col - current_col;
  if (current_col > 0)
    {
      if (remain_col <= buflen)
        {
          putchar ('\n');
          current_col = 0;
        }
      else
        {
          putchar (' ');
          ++current_col;
        }
    }

  fputs (buf.printf, stdout);
  free (buf.printf);
  current_col += buflen;
}