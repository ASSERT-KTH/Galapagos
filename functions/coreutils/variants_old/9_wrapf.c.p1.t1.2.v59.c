wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;

  va_start (args, message);
  buflen = vsnprintf (NULL, 0, message, args); // calc required size
  buf = (char *)malloc((buflen + 1) * sizeof(char)); // allocate memory space
  if(buf == NULL) xalloc_die(); // check if malloc returned NULL pointer 

  vsnprintf (buf, buflen + 1, message, args); // write formatted output to string
  va_end (args);

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

  fputs (buf, stdout);
  free (buf);
  current_col += buflen;
}