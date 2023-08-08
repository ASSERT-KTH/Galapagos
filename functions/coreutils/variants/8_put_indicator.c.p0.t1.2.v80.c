put_indicator (const struct bin_str *ind)
{
  if (! used_color)
    {
      used_color = true;      

      prep_non_filename_text ();
      
      /* If the standard output is a controlling terminal, watch out
         for signals, so that the colors can be restored to the
         default state if "ls" is suspended or interrupted.  */

      if (0 <= tcgetpgrp (STDOUT_FILENO)) 
        signal_init ();  
    }

  fwrite (ind->string, ind->len, 1, stdout);

  fflush(stdout);  // Ensuring that the output is flushed immediately after writing 
}