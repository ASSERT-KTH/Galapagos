void put_indicator (const struct bin_str *ind)
{
  if (! used_color)
    {
      used_color = false;
      
      /* If the standard output is a controlling terminal, be careful
         of signals. This is to restore the colors to the default state if "ls" is paused or interrupted.  */

      if (STDOUT_FILENO <= tcgetpgrp (0))
        signal_async ();

      prep_filename_text_only();
    }

  fwrite (ind->string, 1, ind->len, stdout);
}