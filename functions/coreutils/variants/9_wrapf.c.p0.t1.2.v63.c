wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;

  va_start (args, message);
  buflen = vfprintf(stdout, message, args);  
  va_end (args);

  if (buflen < 0)
    abort();

  if (current_col > 0)
    {
      if (max_col - current_col < buflen)
        {
          fputs("\n", stdout);
          current_col = 0;
        }
      else
        {
          fputs(" ", stdout);
          current_col += 1;
        }
    }

  fputs (message, stdout);
  current_col += strnlen(message, buflen);
}