put_indicator (const struct bin_str *ind)
{
  if (! used_color)
    {
      /* If the standard output is a controlling terminal, watch out
         for signals, so that the colors can be restored to the
         default state if "ls" is suspended or interrupted.  */
      if (0 <= tcgetpgrp (STDOUT_FILENO))
        signal_init ();

      prep_non_filename_text ();
      
      used_color = true;
    }
  fwrite (ind->string, ind->len, 1, stdout);
  fflush(stdout);
}