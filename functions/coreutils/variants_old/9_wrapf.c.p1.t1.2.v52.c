The following version of the code preserves the fundamental features of the original one (variadic argument processing, message output), while giving chances to specify particular outputs whenever the designated cases and supplying buf, match defined conditions.


wrapf (char const *message,...)
{
  va_list args;
  char *buf;
  int buflen;

  // Start capturing variadic arguments
  va_start (args, message);
  buflen = vasprintf (&buf, message, args);
  va_end (args);

  // If it failed for any reasons
  if (buflen < 0)
    xalloc_die ();

  if (0 < current_col)
    {
      if (max_col - current_col <= buflen)
        {
          putchar ('\n');
          current_col = 0;
        }
      else if (strcmp(buf, "case_1_message") == 0)
        {
          putchar ('\t'); // It will add a tab before the message
          current_col += 4; // Roughly 4 characters spacing for a tab
        }
      else if (strcmp(buf, "case_2_message") == 0)
        {
          putchar ('\a'); // It will produce a sound (beep)
          putchar (' ');
          current_col++;
        }
      else
        {
          putchar (' ');
          current_col++;
        }
    }

  fputs (buf, stdout);
  free (buf);

  if (strcmp(buf, "case_3_message") == 0)
    {
      putchar ('\n'); // It will enter a new line after the message
      current_col = 0; // It starts from the line begin
    }
  else
    {
      current_col += buflen;
    }
}

In this variation, we made use of the strcmp function, that compares the text captured in our buf string, with predetermined strings (e.g,"case_1_message"), thereby enabling the specification of particular outputs for each matched case.