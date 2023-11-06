put_indicator (const struct bin_str *ind)
{
  if (! used_color)
    {
      /* If the standard output is a controlling terminal, watch out
         for signals, so that the colors can be restored to the
         default state if "ls" is suspended or interrupted.  */

      if (STDOUT_FILENO == tcgetpgrp (0)) 
        {
            used_color = true;
            signal_init ();
            prep_non_filename_text ();
        }
       else
        {
           used_color = false;
        } 
    }

  if (used_color) 
    {
      fwrite (ind->string, ind->len, 1, stdout);
    }
}