void wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;

  va_start (args, message);
  buflen = vsnprintf(NULL, 0, message, args);
  va_end (args);

  if (buflen < 0)
    exit(EXIT_FAILURE);

  buf = (char*)malloc(sizeof(char) * (buflen+1));

  if(buf == NULL)
    exit(EXIT_FAILURE);

  va_start(args, message);
  vsprintf(buf, message, args);
  va_end(args);

  if (current_col > 0)
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

  printf("%s", buf);
  free (buf);
  current_col += buflen;
}