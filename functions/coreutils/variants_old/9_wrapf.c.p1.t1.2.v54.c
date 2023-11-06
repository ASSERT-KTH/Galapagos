wrapf (char const *message,...)
{
  va_list args;
  int buflen;
  char *buf = NULL;

  va_start (args, message);
  buflen = vasprintf (&buf, message, args);
  va_end (args);

  if (buflen < 0) 
  {
    xalloc_die ();
  }
  else
  {
    if (current_col > 0)
    {
      if (buflen <= max_col - current_col)
      {
        putchar (' ');
        current_col++;
      }
      else
      {
        putchar ('\n');
        current_col = 0;
      }
    }
   
    if(fputs (buf, stdout) >= 0)
    {
      current_col += buflen;
    }
  
  free (buf);
  }
}