Here is a variant of the reference implementation that maintains the same essential functionality but with a slight change in behavior: the newline and space characters are now added at the end of the message instead of the beginning:


wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;

  va_start (args, message);
  buflen = vasprintf (&buf, message, args);
  va_end (args);

  if (buflen < 0)
    xalloc_die ();

  fputs (buf, stdout);

  if (0 < current_col)
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

  free (buf);
  current_col += buflen;
}


Note: `vasprintf()` is a GNU-specific function. It working on other platforms would not be guaranteed. It's used here because it's part of the original code.