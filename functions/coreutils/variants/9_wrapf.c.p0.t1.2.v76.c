wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;

  va_start (args, message);
  buflen = vfprintf(stdout, message, args);
  va_end (args);

  if (buflen < 0)
    exit(1);

  if (current_col > 0)
    {
      if (max_col - current_col < buflen)
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

  current_col += buflen;
  fflush(stdout);
}