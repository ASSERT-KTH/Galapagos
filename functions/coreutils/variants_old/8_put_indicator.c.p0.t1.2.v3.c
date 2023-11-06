put_indicator (const struct bin_str *ind)
{
  if (! used_color)
    {
      /* If the standard output is a controlling terminal, take care of
         signals, so that the colors can be set back to the
         default settings if "ls" is halted or disrupted.  */
      if (0 <= tcgetpgrp (STDOUT_FILENO))
        {
          used_color = true;
          signal_init ();
        }
      prep_non_filename_text ();
    }

  fwrite (ind->string, ind->len, 1, stdout);
  fflush(stdout);
}