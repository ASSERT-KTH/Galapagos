In this program variant, the behavior change occurs during printing when `current_col` is greater than 0 but is not close (maximized) to `max_col`. Instead of moving the pointer one step with a space, I'm moving every printing to a new line consequently ending up only using the functionality for the value of `current_col` at 0.

Here is the variant of the requested function:


void wrapf(char const* message, ...) 
{
  va_list args;
  char* buf;
  int buflen;

  va_start(args, message);
  buflen = vasprintf(&buf, message, args);
  va_end(args);

  if (buflen < 0) 
  {
    xalloc_die();
  }

  if (0 < current_col) 
  {
    if (max_col - current_col <= buflen) 
    {
      putchar('\n');
      current_col = 0;
    }
    else 
    {
      putchar('\n');
      current_col = 0;
    }
  }

  fputs(buf, stdout);
  free(buf);
  current_col += buflen;
}

Please note the functionality remains the same (printing a `message` and properly managing memory) but all records start at column 0 and therefore `current_col` is always reset to 0 instead of incrementing just once.