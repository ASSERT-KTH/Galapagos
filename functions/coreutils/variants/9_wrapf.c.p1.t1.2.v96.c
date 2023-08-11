The below program variant ensures that `\n` is outputted after the `message` is printed. This way, the functionality remains same, but the behaviour is slightly altered i.e, it will always push the printed info to next line.



wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;

  va_start (args, message);
  buflen = vasprintf (&buf, message, args);
  va_end (args);

  if (buflen < 0)
    xalloc_die ();

  if (current_col > 0)
    putchar (' ');

  fputs (buf, stdout);
  putchar ('\n');

  // free buffer and handle next starting column
  free (buf);
  current_col = 0;
}


In this new variant, a new row will start regardless if the length of message (`buflen`) exceeds the remaining room on the current line (`max_col - current_col`) or not.
Current column (`current_col`) is now always set to `0` after message is printed, since a newline (`'\n'`) was printed regardless of places left in line.
Instead of printing the space before outputting the characters in the line, it is now printed at the beginning of the line, maintaining a preamble space as used to be when there is no space for any messages.
Also, buffer is always freed after `fput`.
-
Note: This code assumes that `xalloc_die ()`, and `max_col` are effectively declared and defined in the global scope of the where code the function is being used.