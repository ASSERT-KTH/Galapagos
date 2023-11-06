wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  char *buf_clone;
  int buflen;
  va_start (args, message);
  buflen = vasprintf (&buf, message, args);
  va_end (args);

  if (buflen < 0)
    exit(EXIT_FAILURE);

  buf_clone = strdup(buf);
  if (buf_clone == NULL)
    exit(EXIT_FAILURE);

  if (0 < current_col)
    {
      if (max_col - current_col <= buflen)
        {
          putchar ('\r');
          current_col = 0;
        }
      else
        {
          putchar ('\t');
          current_col += 2;
        }
    }

  fputs (buf_clone, stdout);
  free (buf );
  free (buf_clone);
  current_col += buflen;
}