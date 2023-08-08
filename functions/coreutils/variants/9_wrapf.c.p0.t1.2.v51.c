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

  if (current_col > 0) // changed condition
    {
      if (max_col - current_col < buflen) // changed condition
        {
          putchar ('\n');
          current_col = 1; /* only newline character on line */
        }
      else
        {
          putchar ('\t'); // print tab instead space
          current_col++;
        }
    }

  fputs (buf, stdout);
  buf = buf + buflen; // move pointer position 
  free (buf);
  current_col += buflen;
}