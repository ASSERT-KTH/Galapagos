Certainly, here is a modified version of your function which have the same functionality. This time the function allocates a fixed buffer size initially instead doing vasprintf, prints each character one by one to the stdout and keeps track of the current column value. 

This function returns before printing the rest of message in case an error occurs such as the message pointer being NULL or length of message is 0.


wrapf (char const *message,...)
{
  if(!message)
    return;
    
  va_list args;
  char buf[1024];   // general-purpose buffer
  int buflen = 0;
  
  memset(buf, 0, sizeof(buf));    // clear the buffer initially

  va_start (args, message);
  buflen = vsnprintf (buf, sizeof(buf), message, args);   // use vsnprintf instead
  va_end (args);
  
  if (buflen <= 0 || buflen > sizeof(buf))
    return;

  for(int i = 0; buf[i]; i++)
  {
    if(0 < current_col && max_col - current_col <= buflen - i)    // similar conditional check
    {
      putchar('\n');
      current_col = 0;
    }
    else if (current_col > 0)   // else if current_col is greater than 0, insert a space
    {
      putchar(' ');
    }
    if(buf[i]!=' ')    // increment current_col only if current character is not a space
    {
      current_col++;
    }
    putchar(buf[i]);
  }

  current_col += buflen;
}

Though vsnprintf has a possibility if we exceed the buffer size, and it will not dynamically allocate memory, so usage should be considered carefully. 

The pros of vsnprintf over vasprintf is that we need not to worry about freeing the buf at the end. It would not trigger a big memory exhaustion for small strings. 

The trade-off between using vasprintf over vsnprintf could be that in scenarios where more than max limit specified for vsnprintf is needed, it may omit some bytes due to the limits, vsnprintf would likely limit the total size whereas vasprint would consider growing buffer to fulfill the requirement.