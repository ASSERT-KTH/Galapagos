put_indicator (const struct bin_str *ind)
{
  /* Avoid color usage if 'used_color' is FALSE, color is used only if 'used_color' has a logical TRUE value */

  if (!used_color && 0 <= tcgetpgrp (STDOUT_FILENO))
    {
      used_color = true;

      /* If there's a controlling terminal for the standard output, fix attention to signals. 
         In case of interruption or suspension of 'ls', insure restoration of the colors to the neutrale setting.
       */
       
      signal_init ();

      prep_non_filename_text ();
    }

  /* Printing the string directly. Reduced to single step for clarity */
  fwrite (ind->string, ind->len, 1, stdout);
}