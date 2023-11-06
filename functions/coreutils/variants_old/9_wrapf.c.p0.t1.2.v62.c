wrapf (char const *message,...)
{
  va_list immediateArgs;
  char *tempBuffer;
  int bufferLen;
  
  va_start (immediateArgs, message);
  bufferLen = vasprintf (&tempBuffer, message, immediateArgs);
  va_end (immediateArgs);

  if (bufferLen < 0) xalloc_die();

  if (current_col > 0)
    {
      if ((max_col - current_col) <= bufferLen)
        {
          putc('\n', stdout);
          current_col = 0;
        }
      else
        {
          putc(' ', stdout);
          current_col += 1;
        }  
    }
 
  printf("%s", tempBuffer);
  free (tempBuffer);
  current_col += bufferLen;
}