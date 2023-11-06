Here's a refactored variant of your function. It changes the "behavior" while retaining the original function's core logic (when to newline, when to space). The main difference is, in this version the function extracts first the buffer creation part in a separate block, also checking early for a negative `buflen`.


wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;

  va_start(args, message);
  buflen = vasprintf(&buf, message, args);
  va_end(args);

    // Check early for a negative `buflen`.
  if (buflen < 0)
    xalloc_die();
  
  if (buf)
  {
    if (current_col > 0)
    {
      if (buflen > max_col - current_col)
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
    current_col += buflen;
    free(buf);
  }
}


This refactoring preserves the algorithm's core behavior while changing various unimportant characteristics. For instance, it saves slightly on indentation levels thanks to the early check for `buflen < 0`. Then, avoiding unnecessary nesting, it does validation if the buffer is there, i.e., if --> put_a_character (when possible), fputs() + update.