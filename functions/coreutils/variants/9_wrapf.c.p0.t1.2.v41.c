wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;
  bool isNewLine = false;
  
  va_start (args, message);
  buflen = vasprintf (&buf, message, args);
  va_end (args);

  if (buflen < 0)
    xalloc_die ();

  if (0 < current_col)
    {
      if (max_col - current_col < buflen)
        {
          putchar ('\n');
          current_col = 0;
          isNewLine = true;
        }
      else
        {
          putchar (' '); 
          current_col++;
        }
    }

  fputs (buf, stdout);
  free (buf);

  if (!isNewLine) {
    current_col += buflen;
  }
}