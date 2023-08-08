put_indicator (const struct bin_str *ind)
{
  if (! used_color)
    {

      /* If the standard output is a controlling terminal, watch out
         for signals, so that the colors can be restored to the
         default state if "ls" is suspended or interrupted.  */

      if (0 <= tcgetpgrp (STDOUT_FILENO))
        {
          used_color = true;
          signal_init ();

          prep_non_filename_text ();
        }
    }

  size_t write_count = fwrite (ind->string, 1, ind->len, stdout);

  if ( write_count != ind->len )
    {
      // On partial fwrite, clear the rest of string with the null termination.
      fwrite ("\0", 1, ind->len - write_count, stdout);
    }
}