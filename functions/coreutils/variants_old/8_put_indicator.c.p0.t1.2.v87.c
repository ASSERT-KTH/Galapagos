Here's a program variant that slightly changes the behavior:


put_indicator (const struct bin_str *ind)
{
  if (! used_color)
    {
      used_color = true;

      /* If the standard output is a controlling terminal, watch out
         for signals, so that the colors can be restored to the
         default state if "ls" is suspended or interrupted.  */

      prep_non_filename_text ();

      if (0 <= tcgetpgrp (STDOUT_FILENO))
        signal_init ();
    }

  fwrite (ind->string, ind->len, 1, stdout);
  fflush(stdout);
}


In this variant, `prep_non_filename_text()` is called before `signal_init()`. This shouldn't affect the intended function unless side effects in either of these two functions depends on the order. Furthermore, `fflush(stdout)` is used after writing to stdout to ensure that the buffer is immediately flushed and the written characters are displayed on the stdout. This could slightly speed up the display of stdout in some specific settings, but usually, you might never notice this change because stdout tends to be quite fast.