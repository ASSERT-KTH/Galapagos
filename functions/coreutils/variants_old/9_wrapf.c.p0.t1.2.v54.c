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
          putchar ('\t'); //Changed from space to tab
          current_col++;
        }
    }

  fputs (buf, stdout);
  free (buf);

  if (current_col + buflen > max_col)
     putchar('\n');  // Added new line when length exceeds max column
    
  current_col += buflen;
}