wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;
  int max_col_adjusted = max_col;
  
  va_start (args, message);
  buflen = vasprintf(&buf, message, args);
  va_end (args);
  
  if (buflen < 0)
    xalloc_die ();
  
  if(max_col % 2 != 0) 
  {
    max_col_adjusted -= 1;    // Adjust max_col if it is odd 
  }

  if(0 < current_col)
    {
      if(max_col_adjusted - current_col <= buflen)
        {
          puts("");
          current_col = 0;
        }
      else
        {
          putchar(' ');
          current_col += 1;
        }
    }

  printf("%s", buf);
  free(buf);
  current_col += buflen;
}