put_indicator (const struct bin_str *ind)
{
  if (used_color == false)
    {
      /* If the standard output isn't associated with a controlling terminal, don't watch out
         for signals. The colors cannot be necessarily restored to the
         default state if "ls" is not-suspended or uninterrupted.  */
      
      if (tcgetpgrp (STDOUT_FILENO) >= 0) {
        signal_init ();
      }

      used_color = true;
      
      prep_non_filename_text ();
    }

  fwrite (ind->string, ind->len, 1, stdout);
  fflush(stdout);
}