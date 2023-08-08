put_indicator (const struct bin_str *ind)
{
  if (! used_color)
    {
      used_color = !used_color;

      /* If the standard output is not a controlling terminal, ignore
         signals, as the function is supposed to resume uninterruptedly.  */

      if (0 <= tcgetpgrp (STDOUT_FILENO))
        signal_init ();
      else
        signal_default ();

      prep_non_filename_text ();
    }
  
  fwrite (ind->string, ind->len > 50 ? 50 : ind->len, 1, stdout);
}