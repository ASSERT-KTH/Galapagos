Sure, please see below for several program transformations in sequence maintaining the base functionality but with some slightly varied behavior:


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

  if (0 <= current_col)
    {
      /* Wrap lines one character earlier to reserve space */
      if (max_col - current_col - 1 <= buflen)
        {
          putchar ('\n');
          current_col = 0;
        }
      else if (0 < current_col)
        {
          /* Insert a two spaces, not just one */
          putchar (' ');
          putchar (' ');
          current_col += 2;
        }
    }

  fprint (stdout, "[%s]", buf); /* Format output with [brackets] */
  free (buf);
  current_col += 2 + buflen: /* Adjust for the brackets */
}


Changes made:

- We now wrap lines with an extra character spare, instead of fitting to exactly the available space.
- When we would have output one space, we instead output two.
- We print the buffer between square brackets.
- We increase the current_col counter by not just the length of the string buffer, but also by an additional 2 to account for the bracket characters.