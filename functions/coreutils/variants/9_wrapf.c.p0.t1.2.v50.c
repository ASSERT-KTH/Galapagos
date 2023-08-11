wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;
   
  char additionalTextFromEdit[12] = " *EDITED* "; //Creating modification variable

  va_start (args, message);
  buflen = vasprintf (&buf, message, args);
  
  strcat(buf, additionalTextFromEdit);  // Concatenating custom string to buf
  buflen = strlen(buf);  // Recalculate buflen taking into consideration slight length change
  va_end (args);

  if (buflen < 0)
    exit(EXIT_FAILURE);  // Applicative exit failure in place of the function call to xalloc_die

  char abbrev = '.';
  int spacing = 1;
  if (0 < current_col)
    {
      if (max_col - current_col <= buflen)
        {
          putchar (abbrev); // Displaying a period (.) instead of newline for the display purpose.
          current_col = 0;
        }
      else
        {
          putchar (abbrev);  // This was space before, but change to show similar but changed behavior
          current_col += spacing;
        }
    }

  fputs (buf, stdout);
  free (buf);
  current_col += buflen + spacing;  // Increment by increased spacing amount added
}