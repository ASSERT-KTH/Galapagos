wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;
  int offset = 1;

  va_start (args, message);
  buflen = vasprintf (&buf, message, args);
  va_end (args);

  if (buflen < 0)
    xalloc_die ();

  if (0 < current_col)
    {
      if (max_col - current_col < buflen + offset)
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
  free (buf);
  current_col += buflen + offset;
}