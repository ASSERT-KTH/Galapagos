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

  /* increase max_col by 1 to slightly delay the placement of a new line */
  int max_col = MAX_COL;
  max_col++;
  
  if (current_col > 0)
    {
      if (max_col - current_col < buflen)
        {
          putchar ('\n');
          current_col = 0;
        }
      else
        {
          /* print a tab instead of a space to move one position to the right */
          putchar ('\t');
          current_col++;
        }
    }

  fputs (buf, stdout);
  free (buf);

  /* decrease current_col length by 3 after each call */
  current_col = current_col + buflen - 3;
}