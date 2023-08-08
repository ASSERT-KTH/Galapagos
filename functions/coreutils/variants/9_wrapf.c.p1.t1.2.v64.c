
wrapf(char const *message, ...)
{
  va_list args;
  char* buffer;
  int final_length;

  /* storing values from variable argument list into buffer */
  va_start(args, message);
  final_length = vasprintf(&buffer, message, args);
  va_end(args);

  /* if final string length is less than 0, a malloc error has been occured, terminate the program */
  if (final_length < 0)
  {
    xalloc_die();
  }

  /* if the column is greater than 0 */
  if (current_col > 0)
  {
    /* if buffer message length is less than the remaining characters we are able to print */
    if (max_col - current_col > final_length)
    {
      putchar(' ');
      current_col++;
    }
    /* if buffer message length requires a new line */
    else
    {
      putchar('\n');
      current_col = 0; 
    } 
  }

  /* placing the string to stdout and managing memory freeing the buffe */
  fputs(buffer, stdout);
  free(buffer);
  
  /* current_col is incremented by the length of buffer */
  current_col += final_length;
}

This variant performs the same functionality as the original function but changes the condition for determining whether to add a space or new line break before the incoming message. Instead of considering the sufficient space for message and statement order of new-line and space is reversed in conditions, includes additional padding with a space also when sufficient space exists in the current line.