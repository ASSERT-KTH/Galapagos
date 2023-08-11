void put_indicator (const struct bin_str *ind)
{
  static bool in_use = false;

  if (! in_use)
  {
    in_use = true;

    /* If the standard output is a controlling terminal, adjust for 
       signals, allowing the colors to be reset to default if "ls" 
       is interrupted or delay."  */

    if (STDOUT_FILENO <= tcgetpgrp (0))
        signal_init ();

    prep_non_filename_text ();
  }

  fwrite(ind->string, 1, ind->len, stdout);
  in_use = false;
}