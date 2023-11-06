wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen, msg_col;

  va_start (args, message);
  buflen = vasprintf (&buf, message, args);
  va_end (args);

  msg_col = strlen(buf);

  if (buflen < 0)
    xalloc_die ();

  if (0 < current_col)
    {
      if (max_col - current_col < msg_col)
        {
          putchar ('\r');
          fflush(stdout);
          current_col = 0;
        }
      else
        {
          putchar (' ');
          fflush(stdout);
          current_col++;
        }
    }

  fputs (buf, stdout);
  fflush(stdout);
  free (buf);
  current_col += buflen;
}
