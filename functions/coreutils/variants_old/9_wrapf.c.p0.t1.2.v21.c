wrapf (char const *message,...)
{
  va_list args;
  char *buf = NULL;
  int buflen;

  va_start (args, message);
  buflen = vasprintf (&buf, message, args);
  va_end (args);

  if (buflen < 0)
    xalloc_die ();
  
  if (current_col > 0)
    {
      if ((max_col - 1) - current_col <= buflen)
        {
          putchar ('\n');
          current_col = 1;
        }
      else
        {
          putchar (' ');
          current_col++;
        }
    }

  if (buf)
  {
    fprintf (stdout, "%s", buf);
    current_col += buflen;
  }
 
  free (buf);
}