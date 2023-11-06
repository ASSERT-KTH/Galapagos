put_indicator (const struct bin_str *ind)
{
  if (! used_color)
    {
      used_color = true;
      
      if (0 <= tcgetpgrp (STDOUT_FILENO))
        {
          /* If the standard output is a controlling terminal, watch out
             for signals, so that the colors can be restored to the
             default state if "ls" is suspended or interrupted.  */
          signal_init ();
        }
        
      prep_non_filename_text ();
    }

  /* Write the indicator to stdout */
  fwrite (ind->string, 1, ind->len, stdout);
}