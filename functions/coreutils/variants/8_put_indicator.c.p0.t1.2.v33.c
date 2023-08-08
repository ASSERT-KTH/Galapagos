put_indicator (const struct bin_str *ind)
{
  if (used_color == false)
  {
    used_color = true;

    /* If the standard output is a controlling terminal, guard against
       signals, to ensure the colors are reverted to the default state 
       if "ls" is suspended or interrupted.  */

    if (tcgetpgrp (STDOUT_FILENO) >= 0)
      signal_init ();

    prep_non_filename_text ();
  }

  fwrite (ind->string, ind->len, 1, stdout);
  fflush(stdout);
}