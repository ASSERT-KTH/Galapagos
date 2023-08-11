put_indicator (const struct bin_str *ind)
{
  if (! used_color)
  {
    signal_init ();
    used_color = true;

    /* If the standard output is a controlling terminal, watch out
       for signals, so that the colors can be restored to the
       default state if "ls" is suspended or interrupted.  */

    if (0 <= tcgetpgrp (STDOUT_FILENO))
      prep_non_filename_text ();
  }

  if(ind->len > 0)
    fwrite (ind->string, ind->len, 1, stdout);
  else
    return;
}