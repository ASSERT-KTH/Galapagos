wrapf (char const *message,...)
{
  va_list args;
  int newlen;
  char *newbuf;
  
  va_start (args, message);
  newlen = vasprintf (&newbuf, message, args);
  va_end (args);
  
  if (newlen < 0)
    xalloc_die ();
    
  if (current_col > 0)
    {
      if (newlen >= max_col - current_col)
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

  int i = 0;
  while(newbuf[i]){ 
      fputc (newbuf[i], stdout); 
      i++; 
  }

  free (newbuf);
  current_col += newlen;
}