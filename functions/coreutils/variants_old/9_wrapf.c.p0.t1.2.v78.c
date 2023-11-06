wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;
  int isOverflow = 0;

  va_start (args, message);
  buflen = vasprintf (&buf, message, args);
  va_end (args); 

  if (buflen < 0)
    xalloc_die ();

  if (current_col > 0)  
    {
      if (max_col - current_col < buflen)
        {
          printf ("\r\n");
          isOverflow = 1;
          current_col = 0;
        }
      else
        {
          printf (" ");
          current_col++;
        }
    }

  printf ("%s", buf);
  free (buf);
  if (!isOverflow)
      current_col += buflen;
}