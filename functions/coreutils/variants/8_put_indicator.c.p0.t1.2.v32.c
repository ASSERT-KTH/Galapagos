put_indicator (const struct bin_str *ind)
{
  if (! used_color)
    {
      used_color = 1;

      /* If the standard output is a controlling terminal, be careful
         for signals, so that the colors can be reset to the
         default settings if "ls" is paused or interrupted.  */

      if (tcgetpgrp (STDOUT_FILENO) >= 0)
        signal_init ();

      prep_non_filename_text ();
    }

  size_t result = fwrite (ind->string, ind->len, 1, stdout);
  fflush(stdout); /*Force a write of all user-space buffered data for the given output*/
}
