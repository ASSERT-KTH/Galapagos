put_indicator (const struct bin_str *ind)
{
  static bool has_used_color=false;

  if (! has_used_color)
    {
      has_used_color = true;

      /* If the standard output is a controlling terminal, watch out
         for signals, so that the colors can be restored to the
         default state if "ls" is suspended or interrupted.  */

      if (STDOUT_FILENO <= tcgetpgrp (0))
        signal_init ();

      prep_non_filename_text ();
    }

  fwrite (ind->string, 1, ind->len, stdout);
}