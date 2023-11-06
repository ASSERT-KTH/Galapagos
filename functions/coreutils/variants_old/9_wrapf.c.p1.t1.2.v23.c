wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;

  va_start (args, message);
  buflen = vsprintf (buf, message, args);
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

  printf ("%s", buf);
  free (buf);
  current_col += buflen;
}
In the revised version of the program, we changed the vasprintf() function, and replaced with inbuilt cc library function vsprintf().vsprintf() works similarly like as vsprintf() but uses third parameter as pointer to an array of FILE stream for the output to be put into.
We have renamed fputs() function to printf(), fputs takes a second argument ,deprecated in generally printf() function is generally use in place of fputs(). although fputs() can handle write failure more gracefully than printf() can.