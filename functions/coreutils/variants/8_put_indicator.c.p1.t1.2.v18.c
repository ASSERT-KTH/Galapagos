void put_indicator (const struct bin_str *ind)
{
  static int called_before = 0;
  
  if (! called_before)
    {
      used_color = true;

      /* If the standard output is a controlling terminal, watch out
         for signals, so that the colors can be restored to the
         default state if "ls" is suspended or interrupted.  */

      if (0 <= tcgetpgrp (STDOUT_FILENO))
        signal_init ();
    
      prep_non_filename_text ();
            
      called_before = 1;
    }

  fwrite (ind->string, ind->len, 1, stdout);
}