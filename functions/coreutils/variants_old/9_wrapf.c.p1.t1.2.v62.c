Here is a function variant that sticks to the original functionality, the difference being in how memory exceptions are handled when `vasprintf` fails and also extra type checking before freeing `buf`:


wrapf (char const *message,...)
{
  va_list args;
  char *buf = NULL;
  int buflen;
  
  va_start(args, message);
  if ((buflen = vasprintf(&buf, message, args)) < 0)
    {
      fputs("Memory allocation failed.\n",stderr);
      return;
    }
  va_end(args);

  if (0 < current_col)
    {
      if (max_col - current_col <= buflen)
        {
          putchar('\n');
          current_col = 0;
        }
      else
        {
          putchar(' ');
          current_col++;
        }
    }

  fputs(buf, stdout);
  if (buf!=NULL)
    free(buf);

  current_col+=buflen;
}

This code adds type checking before freeing `buf` to avoid double freeing or freeing a non-allocated storage. Also it deals with the exception for the function `vasprintf` returning a negative value differently, by outputting a error message to stderr and returning immediately.