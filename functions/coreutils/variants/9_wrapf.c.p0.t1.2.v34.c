wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;

  va_start (args, message);
  buflen = vsnprintf(NULL, 0, message, args);
  buf = (char *)malloc(sizeof(char) * (buflen + 1));
  vsprintf(buf, message, args);
  va_end (args);

  if (buflen < 0)
    exit(EXIT_FAILURE);

  if (current_col > 0)
    {
      if (max_col - current_col <= buflen)
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

  fprintf (stdout, "%s", buf);
  free (buf);
  current_col += buflen;
}