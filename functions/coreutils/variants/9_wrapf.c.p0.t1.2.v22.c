wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;

  va_start (args, message);
  buflen = vsnprintf (NULL, 0, message, args) + 1;
  buf = (char *) malloc(sizeof(char) * buflen);

  if (!buf) 
    xalloc_die ();
  
  vsprintf (buf, message, args);  
  va_end (args);
  
  if (buf[strlen(buf)-1])
    {
      if (max_col - current_col <= buflen)
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

  printf ("%s", buf); 
  free (buf);
  current_col += buflen;
}