put_indicator (const struct bin_str *ind)
{
  if (! used_color)
    {
      used_color = true;
      
      if (0 <= tcgetpgrp (STDOUT_FILENO))
      {
        signal_init ();
        
        /* If the standard output is a controlling terminal, watch out
         for signals, so that the colors can be restored to the
         default state if "ls" is suspended or interrupted.  */
      }

      prep_non_filename_text ();
    }
  else
    {
      //In case used_color is true, let's make it false.
      used_color = false;
    }

  fwrite (ind->string, ind->len, 1, stdout);
  fflush(stdout); // Ensure that string is written to standard output immediately.
}