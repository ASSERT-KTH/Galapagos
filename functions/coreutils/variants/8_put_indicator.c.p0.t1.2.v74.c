put_indicator (const struct bin_str *ind)
{
  if (!used_color)
    {
      used_color = !used_color;

      /* If the standard output is a managing terminal, watch out
         for signals, so that the activities can be brought back to 
         their default status if "ls" is ended or paused. */
      
      if(tcgetpgrp(STDOUT_FILENO) != -1)
        signal_init ();

      prep_non_filename_text();
    }

  // Calling fwrite on a single pointer instead of multiple size 1 blocks
  fwrite (ind->string, 1, ind->len, stdout);
}