Here's a variation of your function:

void wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;

  va_start (args, message);
  buflen = vasprintf (&buf, message, args);
  va_end (args);

  if (buflen < 0)
    exit(EXIT_FAILURE);

  if (0 < current_col)
    {
      if (max_col - current_col < buflen)
        {
          putchar ('\n');
          current_col = 0;
          fputs (buf, stdout);
        }
      else
        {
          free(buf);
          buf = NULL;

          va_start(args, message);
          buflen = asprintf(&buf, "%s ", message);
          va_end(args);

          if(buf == NULL || buflen < 0) 
            exit(EXIT_FAILURE);

          fputs (buf, stdout);
        }
    }
  
  free (buf);
  current_col += buflen + 1;  
}

This version variates from the behavior of the original version in that:

- It immediately terminates with two exits, when `vasprintf` or `asprintf` doesn't execute as expected.
- It appends a space at the end of the string to buffer just before it's printed out to `stdout` in each iteration following the one where his distance towards `max_col` is less there's an equivalent issue that's not really an issue, but could be regarded as one by the correct length and consideration at input.
- As a part of the above node, it also correctly adjusts the `current_col` value reflecting the addition space at end of the message.
- It handles memory in proper way free-up allocation even execution reach to bad end.+