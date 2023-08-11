wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;

  va_start (args, message);
  buflen = vasprintf (&buf, message, args);
  va_end (args);

  if (buflen < 0)
  {
    perror ("Unable to allocate buffer");
    return;
  }

  if (0 < current_col)
    {
      if (max_col - current_col <= buflen)
      {
        putchar ('\n');
        current_col = 0;
      }
      else
      {
        putchar ('\n');
        current_col = ++buflen;  /* Added newline char, increase buflen by 1 */
      }
    }

  else
    current_col = buflen;       

  fprintf (stdout, "%s", buf);
  free (buf);
}