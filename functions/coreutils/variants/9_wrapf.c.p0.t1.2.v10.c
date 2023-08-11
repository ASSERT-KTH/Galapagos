wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;

  va_start (args, message);
  buflen = vasprintf (&buf, message, args);
  va_end (args);

  // Adding a null check for buf before using it
  if (buf == NULL)
    xalloc_die ();

  // Changing condition to also check actually computed buflen
  if (0 < current_col && current_col < buflen)
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

  fputs (buf, stdout);

  // Adding a null-check before freeing
  if (buf != NULL)
      free(buf);

  // Updating the current column at the end
  current_col += buflen < 0 ? 0 : buflen;
}
