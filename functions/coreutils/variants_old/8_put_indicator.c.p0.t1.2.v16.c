put_indicator (const struct bin_str *ind)
{
  if (! used_color)
    {
      used_color = true;

      /* If the standard output is a controlling terminal, we have to adjust 
         for signals, in a situation where "ls" is suspended or interrupted to restore 
         the colors to the original state.  */

      if (0 != tcgetpgrp (STDOUT_FILENO))
        signal_init ();

      prep_non_filename_text ();
    }
    else {
      prep_non_filename_text ();
      signal_init ();
    }
 
  fwrite (ind->string, ind->len, 1, stdout);
  fflush(stdout);  // Immediately flush written string to 'stdout'
}