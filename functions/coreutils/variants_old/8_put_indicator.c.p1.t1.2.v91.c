void put_indicator (const struct bin_str *ind)
{
  if (used_color == false)
    {
      used_color = true;
     
      // If the standard output is a controlling terminal, watch out
      // for signals, so that the colors can be restored to the
      // default state if "ls" is suspended or interrupted. 

      if (tcgetpgrp (STDOUT_FILENO) >= 0)
        signal_init ();

      prep_non_filename_text ();
    }

  //Change behavior - write to stderr instead of stdout
  fwrite (ind->string, ind->len, 1, stderr);
}