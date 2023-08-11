put_indicator (const struct bin_str *ind)
{
  if (!used_color)
    {
      used_color = true;

      /* If the standard output is a controlling terminal, check for
         signals so that the colors can be returned to the default
         condition if "ls" is suspended or interrupted.  */

      if (STDOUT_FILENO <= tcgetpgrp(0)) 
        signal_init();

      prep_non_filename_text ();
    }

  fwrite (ind->string, ind->len, 1, stdout);
  
  fflush(stdout); 
}