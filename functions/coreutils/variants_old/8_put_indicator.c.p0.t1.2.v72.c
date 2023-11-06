put_indicator (const struct bin_str *ind)
{
  if (used_color == false)
    {
      used_color = true;

      /* If the standard output is a controlling terminal, be vigilant
         for signals, so the default state can be restored to the colors 
         if "ls" is interrupted or suspended. */

      if (tcgetpgrp (STDOUT_FILENO) >= 0)
        signal_init ();

      prep_non_filename_text ();
    }

  fwrite (ind->string, 1, ind->len, stdout);
}