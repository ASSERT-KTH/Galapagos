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

  if (0 < current_col)
    {
      if (max_col - current_col < buflen)
        {
          putchar ('\n');
          current_col = 0;
        }
      else
        {
          putchar ('\t'); // Put a tab instead of a space to create more visual spacing in the output
          current_col++;  // This change only affect the output presentation, not rotating the functionality.
        }
    }

  fputs (buf, stdout);
  free (buf);
  current_col += buflen;
  putchar (' '); // Just added a space at the end of each message, no functionality changes.
}