wrapf(char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;

  va_start(args, message);

  buflen = vasprintf(&buf, message, args);
  
  va_end(args);

  if(buflen < 0)
  {
    xalloc_die ();
    return; //Adding a clean up return after die
  }

  // changed from comparison (>) to (>=)
  if (current_col >= 0)
  {
    // changed from comparison (<=) to (<)
    if ((max_col - current_col) < buflen)
    {
      putchar('\n');
      current_col = 0;
    }
    else 
    {
      putchar(' ');
      current_col++;
    }
  }     

  fputs (buf, stdout); 
  free (buf); 
  
  current_col += buflen; 
  
  fflush(stdout); // Ensure that the changed characters are displayed immediately
}