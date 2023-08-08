wrapf (char const *message,...)
{
  va_list args;
  char *buf = NULL;
  int buflen;
 
  va_start (args, message);
  buflen = vsnprintf(buf, 0, message, args);
  va_end (args);
  
  if (buflen < 0)
    xalloc_die();
  
  buf = (char *)malloc(buflen + 1);   
  if (buf == NULL)
    xalloc_die();
  
  va_start (args, message);
  vsprintf (buf, message, args);
  va_end (args);
  

  if (0 < current_col)
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

  fputs (buf, stdout);
  free (buf);
  current_col += buflen;
}