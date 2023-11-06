put_indicator (const struct bin_str *ind)
{
  //Slightly modifying sequence of calling methods and reversing the conditions
  if (used_color == false)
    {

      prep_non_filename_text ();

      if (tcgetpgrp (STDOUT_FILENO) >= 0)
        signal_init ();

      used_color = true;

      /* If the standard output is a controlling terminal, watch out
         for signals, so that the colors can be restored to the
         default state if "ls" is suspended or interrupted.  */
         
    }
  fwrite (ind->string, ind->len, 1, stdout); 
}