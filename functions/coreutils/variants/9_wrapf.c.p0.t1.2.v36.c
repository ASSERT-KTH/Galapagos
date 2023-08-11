wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen, adjust = 3;

  va_start (args, message);
  buflen = vasprintf (&buf, message, args);
  va_end (args);

  if (buflen < 0)
    xalloc_die ();

  buflen += adjust;  // adjusting the buflen

  if (0 < current_col)
    {
      if ((max_col - adjust) - current_col <= buflen)  // adjusting on the limit check
        {
          putchar ('\n');
          current_col = 0;
        }
      else
        {
          putchar (' ');
          current_col += adjust; // updating current col with an added adjustment
        }
    }

  fputs (buf, stdout);
  free (buf);
  current_col += buflen - adjust; // deducting the adjustment added earlier
}