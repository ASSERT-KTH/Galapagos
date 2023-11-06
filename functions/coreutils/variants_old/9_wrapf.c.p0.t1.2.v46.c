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
      if (max_col - current_col < buflen) /* remove equals sign */
        {
          if(current_col > 0){ /* made sure that multiple space does not precede '\n' */
            putchar (' ');
            current_col++;
          } 
          putchar ('\n');
          current_col = 0;   
        }
      else
        {
          putchar (' ');
          current_col++;
        }
  }

  printf("%s",buf);   /* replaced fputs with printf */
  free (buf);
  current_col += buflen;
}