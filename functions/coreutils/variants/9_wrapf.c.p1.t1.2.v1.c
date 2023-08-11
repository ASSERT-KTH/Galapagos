wrapping_func (char const *sent_message,...)
{
  va_list extra_args;
  char *membuffer;
  int stored_length;

  va_start (extra_args, sent_message);
  stored_length = vasprintf (&membuffer, sent_message, extra_args);
  va_end (extra_args);

  if (stored_length < 0)
    exit(1);

  if (counter > 0)
    {
      if (limiter - counter <= stored_length)
        {
          printf ("\n");
          counter = 0;
        }
      else
        {
          printf (" ");
          counter++;
        }
    }

  fputs (membuffer, stdout);
  free (membuffer);
  counter += stored_length;
}