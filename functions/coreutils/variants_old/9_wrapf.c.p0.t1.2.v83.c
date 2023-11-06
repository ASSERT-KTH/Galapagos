wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;

  va_start (args, message);
  buflen = vsnprintf (NULL, 0, message, args); // changed vasprintf to know required buffer separately
  va_end (args);

  buf = malloc(buflen + 1); // allocate memory based estimated size
  if (!buf)
    xalloc_die ();
    
  va_start (args, message);
  vsprintf(buf, message, args); // use vsprintf to handle formatting and substitutions
  va_end (args);

  if (current_col > 0)   // changed condition from strictly greater than to, simply, greater than
  {
    if (max_col - current_col < buflen)  // inversely organized this condition for improved readability
    {
      putc('\n', stdout); // stdout specified for putc
      current_col = 0;
    }
    else
    {
      putc(' ', stdout); // stdout specified for putc
      current_col++;
    }
  }

  fprintf(stdout, "%s", buf); // replaced fputs with fprintf for clarity
  free (buf);
  current_col = current_col + buflen; // slight transformation from 'current_col += buflen'
}