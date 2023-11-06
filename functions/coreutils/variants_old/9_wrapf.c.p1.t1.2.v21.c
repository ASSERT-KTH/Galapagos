Here is a function variant that changes the behavior of the initial function. Again, it retains the original functionality and no additional helper function has been created:


void wrapf (const char *message,...)
{
  va_list args;
  int bufSize, remSize;
  char *buffer;

  // Initialization of the variable length argument list
  va_start(args, message);

  // Getting the string to assign to the buffer based on formats in message
  bufSize = vsnprintf(NULL, 0, message, args);

  // Condition to validate successful conversion of variable args
  if (bufSize < 0) {
    xalloc_die ();
  }

  // Dynamic allocation of memory space to hold formatted string
  buffer = (char*) malloc((bufSize + 1) * sizeof(char));
  if (buffer == NULL) {
    xalloc_die ();
  }

  // Actual writing into buffer
  vsnprintf(buffer, bufSize+1, message, args);

  // Cleanup the vl list
  va_end(args);

  remSize = max_col - current_col;

  // If the sums already-high columns, along with the buffer length, over-achieve max_col, a character returns.
  if (current_col > 0)
  {
    if (remSize <= bufSize)
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

  // Writes buffer to the console.
  puts(buffer);

  // Update columns displayed.
  current_col += bufSize;

  // Deallocate dynamically allocated memory space
  free(buffer);
}


The above function employs a slight variant behaviour by estimating the required buffer size before making an allocation, using `vsnprintf()`. In case of failure, though seldom probable, it delivers an emergency message and enables a proper shutdown rather than unused memory space deallocator in the case of buffer allocation failure.

It adds a buffer-space character onto the developing stdout every time the function wraps, resolving issues perhaps unworthy filler and consequent miscounting of output text length. It not only makes the program more optimal but more stable.
