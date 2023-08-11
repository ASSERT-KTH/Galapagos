put_indicator (const struct bin_str *ind)
{
  
  if (! used_color)
    {
      used_color = true;

      /* If the standard output is a controlling terminal, watch out
         for signals, so that the colors can be restored to the 
         default state if "ls" is suspended or interrupted.  */
      
      prep_non_filename_text ();

      if (0 <= tcgetpgrp (STDOUT_FILENO))
        signal_init ();
        
    }

  fwrite (ind->string, strlen(ind->string), 1, stdout);
}