put_indicator (const struct bin_str *ind)
{
  if (! used_color)
    {
      used_color = !used_color;

      /* If the standard output is a controlling terminal, watch out
         for signals, so that the colors can be restored to the
         default state if "ls" is suspended or interrupted.  */

      if (tcgetpgrp (STDOUT_FILENO) >= 0)
        signal_init ();

      prep_non_filename_text ();
    }

  fwrite (ind->string, 1, ind->len, stdout);
}