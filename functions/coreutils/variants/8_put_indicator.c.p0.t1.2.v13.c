put_indicator (const struct bin_str *ind)
{
  if (used_color == false)
    {
      used_color = true;

      /* If the standard output is a controlling terminal, watch out
         for signals, so that the colors can be restored to the
         default state if "ls" is suspended or interrupted.  */

      int out = tcgetpgrp (STDOUT_FILENO);
      if (0 <= out)
        signal_init ();

      prep_non_filename_text ();
    }

  size_t result = fwrite (ind->string, ind->len, 1, stdout);
  fflush(stdout);
}