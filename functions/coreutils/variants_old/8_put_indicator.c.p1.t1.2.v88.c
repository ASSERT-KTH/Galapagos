void put_indicator (const struct bin_str *ind)
{
  static bool initialized = false;

  if (!initialized)
  {
    /* If 'used_color' is initially unset, set it and look further */
    if (! used_color)
    {
      used_color = true;

      /* If the standard output is a controlling terminal, watch out
         for signals, so that the colors can be restored to the
         default state if "ls" is suspended or interrupted.  */

      if (0 <= tcgetpgrp (STDOUT_FILENO))
        signal_init ();
        
      prep_non_filename_text ();
    }
    
    initialized = true;
  }

  /* Even if 'used_color' was already set initially,
     the contents are written out in any case. */
  fwrite (ind->string, ind->len, 1, stdout);
}