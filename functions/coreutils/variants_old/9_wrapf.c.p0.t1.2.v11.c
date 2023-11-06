wrapf2 (char const *message, ...) 
{
  va_list args;
  char *buf; 
  int buflen, space_length = 1;

  va_start (args, message);
  buflen = vasprintf (&buf, message, args);
  va_end (args);

  if (buflen < 0)
    exit(EXIT_FAILURE);  

  putchar (' '); // to add a space before displaying the message
  
  if (current_col +  space_length > 0)
  {
    if (max_col - current_col - space_length <= buflen ) 
    {
      putchar ('\r'); // to return to the start of the line before displaying the message
      current_col = 0;
    } 
    else 
    {
  	   current_col += space_length;
    }
  }
  
  fputs (buf, stdout);
  free (buf);
  current_col += buflen;
}
