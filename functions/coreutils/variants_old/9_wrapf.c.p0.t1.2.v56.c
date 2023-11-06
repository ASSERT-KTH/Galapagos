wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;

  va_start (args, message);
  buflen = vsnprintf (NULL, 0, message, args);
  buf = malloc (buflen + 1);
  vsnprintf (buf, buflen + 1, message, args);
  va_end (args);

  if (buf == NULL)
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

  fwrite (buf, sizeof(char), buflen, stdout);
  free (buf);
  current_col += buflen;
}