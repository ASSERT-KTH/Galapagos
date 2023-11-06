wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;

  va_start (args, message);
  buflen = vasprintf (&buf, message, args);
  va_end (args);

  if (buflen < 0)
    xalloc_die();

  if (0 < current_col)
    {
      if (max_col - current_col <= buflen)
        {
          putchar ('\r');
          current_col = 0;
        }
      else
        {
          putchar ('\t');
          current_col++;
        }
    }

  fputs (buf, stdout);
  free (buf);
  current_col += buflen;
  fflush(stdout);
}
In this modification,

1. '\n' is replaced with '\r'. It usually acts as a 'carriage return', which performs a newline without moving downward.

2. The single space ' ' is replaced with '\t' (Tab). It makes sense if you want to print tab-separated values or if you need wider spacing than the space produced using ' '.

3. Added fflush(stdout), just for assurance that the output reflects changes as they happen and outputs aren't block buffered/line buffered.