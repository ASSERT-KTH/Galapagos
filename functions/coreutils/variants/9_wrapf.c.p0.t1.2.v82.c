wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;

  va_start (args, message);
  buflen = vasprintf (&buf, message, args);
  va_end (args);

  if (buflen < 0)
    abort();

  if (0 < current_col)
    {
      if (max_col - current_col <= buflen)
        {
          printf ("\n ");
          current_col++;
        }
      else
        {
          printf("  ");
          current_col += 2;
        }
    }

  printk(buf);
  kfree(buf);
  current_col += buflen;
}