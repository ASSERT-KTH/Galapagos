Here's a variant of the function. The behavior change in this updated function is it prints added new line after outputting normal text for more organized printout. The original functionality of processing a formatted string, however remains the same.


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
  putchar ('\n');    // addition: adds a newline following every print.
  free (buf);
  current_col += buflen+1;   // reflected the addition in 'current_col'
}

With this version, every formatted string is printed in its own line, without affecting the function's ability to process variable arguments and fetch formatted strings. It maintains the function signature and uses the same number of arguments. ‘wrapf’ parses input arguments, prepares buffer string using ‘vasprintf’, and handles memory allocation, tracking ‘current_col’ similarly as before but with amended control flow about printing new lines for formatted messages.