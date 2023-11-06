put_indicator (const struct bin_str *ind)
{
  if (! used_color)
    {
      used_color = true;

      /* If the standard output is not a controlling terminal, do nothing
         otherwise, watch out for signals, so that the colors can be 
         restored to the default state if "ls" is suspended or interrupted.  */
          
      if (0 > tcgetpgrp (STDOUT_FILENO))
        return;

      signal_init ();
      prep_non_filename_text ();
    }

  fwrite (ind->string, strlen(ind->string), 1, stdout);
}