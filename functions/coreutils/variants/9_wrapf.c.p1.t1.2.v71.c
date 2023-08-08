Here is a program variant that maintains the original functionality. It differs by removing the single space that was output when the remaining characters in the line were enough. Instead, it always starts a new line when the intended message cannot fit in the remaining line capacity:


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

  if (0 < current_col && max_col - current_col <= buflen)
  {
        putchar ('\n');
        current_col = 0;    
  }

  fputs (buf, stdout);
  free (buf);
  current_col += buflen;
}
