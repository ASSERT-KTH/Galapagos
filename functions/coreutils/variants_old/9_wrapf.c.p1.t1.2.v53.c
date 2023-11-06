Here is a variant of the program:


wrapf (char const *message,...)
{
  va_list args;
  int buflen;
  char *buf = NULL;
    
  va_start (args, message);
  int num_bytes_need = vsnprintf(buf, 0, message, args);  
  va_end (args);
  
  if (num_bytes_need < 0) 
    xalloc_die ();

  buf = malloc((num_bytes_need+1)*sizeof(char));

  if (!buf)
    xalloc_die ();

  va_start (args, message);
  buflen = vsprintf(buf, message, args);
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

This variant doesn't use the vasprintf() function and tackles memory allocation differently. It calculates needed size, malloc's buffer and uses vsprintf() functions instead. 

This preserves original functionality and gives more staged / explicit control over memory allocation process. We first calculate the size that we'll need for our string with vsnprintf and afterwards support this size with malloc. This explicitization can be beneficial because it allows code writer to step in / add more logic / checks to each of those strictly separated steps in future easily.