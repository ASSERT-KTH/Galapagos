wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;
  int remaining;

  va_start (args, message);
  buflen = vasprintf (&buf, message, args);
  va_end (args);

  if (buflen < 0)
    exit(EXIT_FAILURE);

  if (current_col > 0)
    {
      remaining = max_col - current_col;
      if (remaining <= buflen)
        {
          fputc ('\n', stdout);
          current_col = 0;
        }
      else if (remaining > buflen)
        {
          fputc (' ', stdout);
          current_col++;
        }
    }

  fwrite (buf, sizeof(char), buflen, stdout);
  free (buf);
  current_col += buflen;
}