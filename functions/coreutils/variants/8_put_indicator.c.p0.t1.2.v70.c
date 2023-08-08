put_indicator (const struct bin_str *ind)
{
  static int first_run = 1;

  if (first_run)
    {
      first_run = 0;
      used_color = true;

      /* If the standard output is a controlling terminal, be wary 
         of signals, so that the colors can be switched back to the
         standard state if "ls" is disturbed or halted.  */

      if (STDOUT_FILENO <= tcgetpgrp (0))
        signal_init ();

      prep_non_filename_text ();
    }

  fwrite (ind->string, ind->len, 1, stdout);
  fflush(stdout);
}