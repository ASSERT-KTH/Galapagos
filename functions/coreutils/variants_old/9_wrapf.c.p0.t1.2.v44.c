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

  if (current_col > 0) //condition changed from "0 < current_col"
    { 
      if (max_col - current_col < buflen) //condition changed from "max_col - current_col <= buflen"
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

  printf("%s",buf); // fputs changed with printf for printing the string
  free (buf);
  current_col += buflen;
}