wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;

  va_start (args, message);
  buflen = kvsnprintf (&buf, 0, message, args);
  bool fail = (buflen < 0);
  va_end (args);

  if (fail)
    xalloc_die ();

  if (current_col > 0)
    {
      if (max_col - current_col < buflen)
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

  if (buf != NULL)
    {
      fputs (buf, stdout);
      free (buf);
    }
  
  current_col += buflen;
}