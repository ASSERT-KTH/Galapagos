wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;
  int linefeed_position;

  va_start (args, message);
  buflen = vasprintf (&buf, message, args);
  va_end (args);

  if (buflen < 0)
    xalloc_die ();

  linefeed_position = max_col - current_col;

  if (current_col > 0)
    {
      if (linefeed_position <= buflen )
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
  
  if(buf)
  {
    fputs (buf, stdout);  
    current_col += strlen(buf);
    free (buf);
  }
}