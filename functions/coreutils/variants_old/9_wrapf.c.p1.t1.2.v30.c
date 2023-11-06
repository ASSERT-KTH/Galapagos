Here is the program variant:


wrapf (char const *message, ...)
{
  va_list args;
  char *buf;
  int buflen;

  va_start (args, message);
  buflen = vsnprintf (NULL, 0, message, args);
  va_end (args);

  if (buflen < 0) xalloc_die ();

  buf = (char *) malloc (buflen + 1);

  if (buf == NULL) xalloc_die ();
     
  va_start (args, message);
  vsnprintf (buf, buflen + 1, message, args);
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

Most parts of code are same, but replaced `vasprintf` with `vsnprintf` function. That is because `vasprintf` function is a GNU extension and not standard, may not be available on all platforms. While `vsnprintf` is a function defined in C standard library and widely available. The code also includes malloc for robust dynamic memory allocation compared to `vasprintf`. This keeps functionality same but comportment slightly changed. After processing variadic arguments is done free buffer to release memory. Do note that on failure this code will result in exception or exit properly.