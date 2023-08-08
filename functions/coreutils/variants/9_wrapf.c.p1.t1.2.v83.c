wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;

  va_start (args, message);
  buflen = vsnprintf(NULL, 0, message, args) + 1;
  buf = malloc(buflen);
  if (!buf)
      xalloc_die ();
  vsnprintf(buf, buflen, message, args);
  va_end (args);

  bool isBufferFitsColumn = max_col - current_col <= buflen;

  if (0 < current_col && isBufferFitsColumn)
  {
    putchar ('\n');
    current_col = 0;
  }
  else if (0 < current_col && !isBufferFitsColumn)
  {
    putchar (' ');
    current_col++;
  }

  fputs (buf, stdout);
  free (buf);
  current_col += buflen;
}