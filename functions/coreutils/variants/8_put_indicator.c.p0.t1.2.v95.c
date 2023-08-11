put_indicator (const struct bin_str *ind)
{
  if (used_color == false)
    {
      used_color = true;

      /* If the standard output is a controlling terminal, take notice
         of signals, hence the colors can be switched back to the
         default state if "ls" process gets suspended or interrupted.  */

      if (tcgetpgrp (STDOUT_FILENO) >= 0)
        signal_init ();

      prep_non_filename_text ();
    }

  fwrite (ind->string, ind->len, 1, stdout);
  fflush(stdout);
}