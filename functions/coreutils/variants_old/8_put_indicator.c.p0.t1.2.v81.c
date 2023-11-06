put_indicator (const struct bin_str *ind)
{
  if (! used_color)
    {
      used_color = 1;

      /* If the standard output is a controlling terminal, keep tabs on
         signals, ensuring colors can be reset to the pre-existing settings if "ls" command
         is interrupted or halted.  */

      if (tcgetpgrp (STDOUT_FILENO) >= 0)
        signal_init ();

      prep_non_filename_text ();
    }

  /* Using another function with a similar function for fwrite */
  putc(str[ind->len-1], stdout);
  fputs (ind->string, stdout);
}