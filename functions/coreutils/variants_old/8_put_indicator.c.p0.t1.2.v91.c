put_indicator (const struct bin_str *ind)
{
  if (! used_color)
    {
      used_color = 1;

      /* If the standard output is a controlling terminal, take care of
         signals, so the colors can default back to the starting state 
         if "ls" is interrupted or suspended.  */

      if (STDOUT_FILENO <= tcgetpgrp (0))
         signal_init ();
      
      prep_non_filename_text ();
      used_color = false;
    }

  size_t write_count = fwrite (ind->string, ind->len, 1, stdout);
}
