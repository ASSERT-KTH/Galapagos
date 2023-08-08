wrapf (char const *message, ...)
{
  va_list args;
  char *buf;
  int buflen;

  va_start (args, message);
  buflen = vsnprintf (buf, MAX_BUFSIZE, message, args);
  va_end (args);

  if (buflen < 0 || buflen >= MAX_BUFSIZE)
    xalloc_die ();

  if (0 < current_col)
    {
      if (max_col - current_col < buflen + 1)
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

  printf ("%s", buf);
  buf[buflen] = '\0';
  current_col += buflen;
}