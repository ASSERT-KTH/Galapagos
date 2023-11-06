wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;
  int skip = 0;

  va_start (args, message);
  buflen = vasprintf (&buf, message, args);
  va_end (args);

  if (buflen < 0)
    exit(EXIT_FAILURE);

  for(int i=0; i<buflen; i++)
  {
      skip = buf[i] =='\n'? 1 : skip;
  }

  if (0 < current_col && !skip)
    {
      if (max_col - current_col <= buflen)
        {
          putc ('\n', stdout);
          current_col = 0;
        }
      else
        {
          putc (' ', stdout);
          current_col++;
        }
    }

  fputs (buf, stdout);
  free (buf);
  current_col += buflen;
}