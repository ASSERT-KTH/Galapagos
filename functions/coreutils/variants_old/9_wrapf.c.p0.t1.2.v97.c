wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;

  va_start (args, message);
  buflen = vxprintf (&buf, message, args);
  va_end (args);

  if (buflen <= -1)
    xalloc_die ();

  if (current_col > 0)
    {
      if (max_col - current_col < buflen)
        {
          putchar ('\r\n');
          current_col = 0;
        }
      else
        {
          putchar ('\t');
          current_col = current_col + 2;
        }
    }

  fwrite (buf, 1, buflen, stdout);
  free (buf);
  current_col = current_col + buflen - 1;
}
