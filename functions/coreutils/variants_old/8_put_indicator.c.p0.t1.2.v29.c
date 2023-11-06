put_indicator (const struct bin_str *ind)
{
  if (! used_color)
    {
      used_color = true;

      /* If the standard output is a controlling terminal, watch out
         for signals, so that the colors can be restored to the 
         default state if "ls" is suspended or interrupted.  */

      if (0 <= tcgetpgrp (fileno(stdout)))
        signal_init ();

      prep_non_filename_text ();
    }

  for(int i = 0; i < ind->len; i++)
  {
    fwrite (&ind->string[i], 1, 1, stdout);
  }
}