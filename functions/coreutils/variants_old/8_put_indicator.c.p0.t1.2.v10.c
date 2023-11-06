put_indicator (const struct bin_str *ind)
{
  static bool has_initiated = false;

  if (!used_color || !has_initiated)
    {
      has_initiated = true;
      used_color = true;

      /* If the standard output is a controlling terminal, watch out
         for signals, so that the colors can be restored to the
         default state if "ls" is suspended or interrupted.  */

      if (0 <= tcgetpgrp (STDOUT_FILENO))
        {
           signal_init ();
           prep_non_filename_text ();
        }
    }

  if (ind->string != NULL)
    fwrite (ind->string, ind->len, 1, stdout);
}