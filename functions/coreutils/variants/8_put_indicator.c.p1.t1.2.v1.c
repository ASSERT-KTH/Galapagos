void put_indicator (const struct bin_str *ind)
{
  static bool already_used_color = false;

  if (!already_used_color)
  {
    already_used_color = used_color = true;

    /* If the standard output is a controlling terminal, watch out
       for signals, so that the colors can be restored to the 
       default state if "ls" is suspended or interrupted.  */

    if (0 <= tcgetpgrp (STDOUT_FILENO))
      signal_init ();

    prep_non_filename_text ();
  }

  fwrite (ind->string, ind->len, 1, stdout);

  if(already_used_color && !used_color)
    already_used_color = false;
}