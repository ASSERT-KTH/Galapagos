
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

  if (current_col > 0) // the condition was modified to have a different behavior but still retaining the functionality
    { 
      if (max_col - current_col < buflen) 
        {
          putchar ('\n');
          current_col = 0;
        }
      else
        { 
          putchar (' ');
        }
          current_col++; // moved this line here so to increment the current_col, everytime not tight with buflen.
    }

  fputs (buf, stdout);
  current_col += buflen;
  buflen > 0 ? free(buf) : 0; // by using this conditional expression buflen is checked to free buffer: so it was freed only when buflen is greater than 0.
  
  return current_col; // return the final column, probably more informative than any string
}
