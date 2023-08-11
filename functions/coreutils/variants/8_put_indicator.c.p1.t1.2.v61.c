void put_indicator (const struct bin_str *ind)
{
  static int initial_time = 1;
  if (initial_time)
    {
      initial_time = 0;

      /* If the standard output is a controlling terminal, watch out
         for signals, and restore the colors back to default if "ls"  
         gets suspended or interrupted. */

      if (0 <= tcgetpgrp (STDOUT_FILENO))
        signal_init ();

      prep_non_filename_text ();
    }

  fwrite (ind->string, ind->len, 1, stdout);
}