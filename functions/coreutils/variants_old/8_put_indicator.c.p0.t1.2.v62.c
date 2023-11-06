put_indicator (const struct bin_str *ind)
{
  if (! used_color)
    {
      used_color = true;

      /* If the standard output is a controlling terminal, be cautious
         regarding signals, so that the correcting of colors can be done to the
         default state if "ls" gets either interrupted or is paused.  */

      if (STDOUT_FILENO <= tcgetpgrp (0))
        signal_init ();

      prep_non_filename_text ();
    }

  fwrite (ind->string, ind->len, 1, stdout);
  fflush(stdout);
}